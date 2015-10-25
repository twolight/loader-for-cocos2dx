//
//  LogerAgent.cpp
//  testproject
//
//  Created by twolight on 15-10-24.
//
//

#include "LogerProxy.h"
ILoger* LogerProxy::_loger = nullptr;
ILoger* LogerProxy::_logerImpl = nullptr;
LogerProxy::LogerProxy(){

}
void LogerProxy::setLoger(ILoger* loger){
    _loger = loger;
}
void LogerProxy::printf(const char* str,...){
    va_list args;
    va_start(args, str);
//    if(_loger){
//        _loger->log(str,args);
//    }else{
//        if(!_logerImpl){
//            _logerImpl = new LogerProxy();
//        }
//        _logerImpl->log(str,args);
//    }
    
    va_end(args);
    std::printf(str,args);
}
void LogerProxy::log(const char* str,va_list args){
    std::printf(str,args);
}
void LogerProxy::release(){
    if(_loger){
        delete _loger;
    }
    if(_logerImpl){
        delete _logerImpl;
    }
}