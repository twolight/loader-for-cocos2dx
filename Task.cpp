//
//  Task.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Task.h"
#include "LogerProxy.h"
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
    if(!_isCancel){
        _statu = Statu::RUNNING;
        _thread = new std::thread([this](){
            struct timeval start, end;
            gettimeofday(&start, nullptr);
            _runnable();
            gettimeofday(&end, nullptr);
            LogerProxy::printf("%s runs: %d millis",getName().c_str(),
                               (long long)(end.tv_sec-start.tv_sec)*1000+(end.tv_usec-start.tv_usec)/1000);
            _doneSignal->countDown();
        });
        _thread->detach();
    }
}
/**
 *  Description
 */
void Task::cancel(){
    _isCancel = true;
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