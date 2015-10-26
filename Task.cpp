//
//  Task.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Task.h"

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
            _runnable();
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