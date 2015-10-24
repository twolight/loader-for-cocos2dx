//
//  Wave.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Wave.h"
Wave::Wave(){

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
    for(auto task : _tasks){
        task->start();
    }
}