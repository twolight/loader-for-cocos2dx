//
//  Task.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Task.h"

using namespace std;
Task::Task(TaskRunnable& runnable):
_statu(Statu::PENDING),
_isCancel(false),
_runnable(runnable),
_thread(nullptr){
    
}
Task::~Task(){
    if(_thread){
        delete _thread;
    }
}
void Task::start(){
    if(_isCancel){
        _statu = Statu::RUNNING;
        _thread = new std::thread(_runnable);
        _thread->detach();
    }
}
/**
 *  Description
 */
void Task::cancel(){
    _isCancel = true;
}