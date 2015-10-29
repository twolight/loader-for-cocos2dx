//
//  Loader.cpp
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#include "Loader.h"
#include "LogerProxy.h"
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
        if(_instance->_statu == Statu::RUNNING){
            _instance->_future.get();//Waiting for task done
        }
        delete _instance;
        LogerProxy::destroy();
    }
}
Loader::Loader():
_statu(Statu::PENDING),
_autoDestroy(false){
    
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
void Loader::cancelWave(int waveIndex){
    auto iterator = _waves.find(waveIndex);
    if(iterator != _waves.end()){
        iterator->second->cancel();
    }
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
    _future = std::async(std::launch::async,[this](){
        for(auto& wave : _waves){
            wave.second->start();
        }
        _statu = Statu::COMPLETE;
        if(_autoDestroy){
            destroy();
        }
    });
    
}
void Loader::setLoger(ILoger* loger){
    LogerProxy::setLoger(loger);
}
Statu Loader::getStatu(){
    return _statu;
}
void Loader::setAutoDestroy(bool autoDestroy){
    _autoDestroy = autoDestroy;
}