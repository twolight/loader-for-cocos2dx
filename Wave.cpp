//
//  Wave.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Wave.h"
#include "CountDownLatch.h"
Wave::Wave():
_isCancel(false){

}
Wave::~Wave(){
    for(auto task : _tasks){
        if(task){
            delete task;
        }
    }
    _tasks.clear();
}
void Wave::addTask(Task* task){
    _tasks.push_back(task);
}
void Wave::start(){
    if(_isCancel){
        return;
    }
    int size = _tasks.size();
    CountDownLatch* countDownLatch = new CountDownLatch(size);
    for(auto task : _tasks){
        task->setDownSignal(countDownLatch);
        task->start();
    }
    countDownLatch->wait();
    delete countDownLatch;
}
void Wave::cancel(){
    _isCancel = true;
}