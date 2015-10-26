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
using namespace std;
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
    LogerProxy::destroy();
}
Loader::Loader():
_statu(Statu::PENDING){
    
}
Loader::~Loader(){
    for(auto iterator = _waves.begin();iterator != _waves.end();iterator++){
        Wave* wave = iterator->second;
        if(wave){
            delete wave;
        }
    }
    _waves.clear();
}
Loader* Loader::addTask(Task* task,unsigned waveIndex){
    if(task != nullptr){
        Wave* wave;
        auto iterator = _waves.find(waveIndex);
        if(iterator != _waves.end()){
            wave = iterator->second;
        }else{
            wave = new Wave();
            _waves.insert(make_pair(waveIndex,wave));
        }
        wave->addTask(task);
    }
    return this;
}
void Loader::cancelTask(const std::string& taskName){
    //
    
}

void Loader::clearTask(){
    for(auto iterator = _waves.begin();iterator != _waves.end();iterator++){
        Wave* wave = iterator->second;
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
    std::future<bool> result = std::async(std::launch::async,[this](){
        for(auto& wave : _waves){
            wave.second->start();
        }
        return true;
    });
//    if(result.get()){
//        //Loader load done.
//    }
    _statu = Statu::COMPLETE;
}
void Loader::setLoger(ILoger* loger){
    LogerProxy::setLoger(loger);
}