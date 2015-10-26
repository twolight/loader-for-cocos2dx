//
//  LogerProxy.h
//  testproject
//
//  Created by twolight on 15-10-24.
//
//

#ifndef __testproject__LogerAgent__
#define __testproject__LogerAgent__
#include "ILoger.h"
class LogerProxy : public ILoger{
private:
    static ILoger* _loger;
    static ILoger* _logerImpl;
    LogerProxy();
    static void release();
    void log(const char* str) override;
public:
    static void printf(const char* str,...);
    static void setLoger(ILoger* loger);
};
#endif /* defined(__testproject__LogerProxy__) */
