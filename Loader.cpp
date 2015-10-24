//
//  Loader.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Loader.h"
#include "LogerProxy.h"
#include <future>
Loader* Loader::_instance = nullptr;
Loader* Loader::getInstance(){
    if(_instance == nullptr){
        _instance = new Loader();
    }
    return _instance;
}
void Loader::destroy(){
    if(_instance){
        delete _instance;
    }
}
Loader::Loader():
_statu(Statu::PENDING){
    
}
Loader::~Loader(){
    for(auto wave : _waves){
        if(wave){
            delete wave;
        }
    }
    _waves.clear();
}
Loader* Loader::addTask(const std::string& taskName,Task* task,unsigned waveIndex){
    if(task != nullptr){
        Wave* wave;
        if(waveIndex < _waves.size()){
            wave = _waves[waveIndex];
            
        }else{
            wave = new Wave();
        }
        wave->addTask(task);
    }
    task->setName(taskName);
    return this;
}
void Loader::cancelTask(const std::string& taskName){
    //
    
}

void Loader::clearTask(){
    for(auto wave : _waves){
        if(wave){
            delete wave;
        }
    }
    _waves.clear();
    _statu = Statu::PENDING;
}
void Loader::start(){
    if(_statu != Statu::PENDING){
        return;
    }
    _statu = Statu::RUNNING;
    clock_t startTime = clock();
    std::future<bool> result = std::async(std::launch::deferred,[this](){
        for(auto wave : _waves){
            wave->start();
        }
        return true;
    });
    if(result.get()){
        //Loader load done.
        
    }
    clock_t endTime = clock();
    LogerProxy::printf("Loader done runs: %d millis",startTime-endTime);
    _statu = Statu::COMPLETE;
}
void Loader::setLoger(ILoger* loger){
    LogerProxy::setLoger(loger);
}