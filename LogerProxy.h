//
//  LogerProxy.h
//  loader-for-cocos2dx
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
    ~LogerProxy();
    void log(const char* str) override;
public:
    /**
     *  Delete the ILoger object.
     */
    static void destroy();
    /**
     *  Print log.
     *
     *  @param str A formate string.
     *  @param ... Some params.
     */
    static void printf(const char* str,...);
    /**
     *  Set a custom log.
     *
     *  @param loger A custom log.
     */
    static void setLoger(ILoger* loger);
};
#endif /* defined(__testproject__LogerProxy__) */
