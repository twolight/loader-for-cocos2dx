//
//  Task.cpp
//  loader-for-cocos2dx
//
//  Created by twolight on 15-10-22.
//
//

#include "Task.h"
#include "LogerProxy.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
#include "platform/android/jni/JniHelper.h"
#endif

using namespace std;
Task::Task(const std::string& name,TaskRunnable& runnable):
_statu(Statu::PENDING),
_isCancel(false),
_runnable(runnable),
_thread(nullptr),
_name(name),
_doneSignal(nullptr){
    
}
Task::~Task(){
    if(_thread){
        delete _thread;
    }
}
void Task::start(){
    _statu = Statu::RUNNING;
    _thread = new std::thread([this](){
        
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        JavaVM *vm;
        JNIEnv *env;
        vm = JniHelper::getJavaVM();
        
        vm->AttachCurrentThread(&env, NULL);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        auto pool = cocos2d::ThreadHelper::createAutoreleasePool();
#endif
        struct timeval start, end;
        gettimeofday(&start, nullptr);
        _runnable();
        gettimeofday(&end, nullptr);
        LogerProxy::printf("%s runs: %d millis",getName().c_str(),
                           (long long)(end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000);
        _doneSignal->countDown();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        vm->DetachCurrentThread();
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        ThreadHelper::releaseAutoreleasePool(pool);
#endif
    });
    _thread->detach();
}
void Task::setName(const std::string &name){
    _name = name;
}
std::string Task::getName(){
    return _name;
}
void Task::setDownSignal(CountDownLatch* doneSignal){
    _doneSignal = doneSignal;
}