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
LogerProxy::~LogerProxy(){
}
void LogerProxy::setLoger(ILoger* loger){
    _loger = loger;
}
void LogerProxy::printf(const char* formate,...){
    int length = 1024;
    char buf[length];
    int result = -1;
    va_list args;
    va_start(args,formate);
    result = vsnprintf(buf,length,formate, args);
    va_end(args);
    if(result >= 0){
        if(_loger){
            _loger->log(buf);
        }else{
            if(!_logerImpl){
                _logerImpl = new LogerProxy();
            }
            _logerImpl->log(buf);
        }
    }
}
void LogerProxy::log(const char* str){
    std::printf("%s\r\n",str);
}
void LogerProxy::destroy(){
    if(_loger){
        delete _loger;
    }
    if(_logerImpl){
        delete _logerImpl;
    }
}