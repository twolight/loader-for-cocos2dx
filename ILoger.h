//
//  ILoger.h
//  loader-for-cocos2dx
//
//  Created by twolight on 15-10-24.
//
//

#ifndef __testproject__ILoger__
#define __testproject__ILoger__

class ILoger{
public:
    virtual ~ILoger(){};
    /**
     *  If want to provide a loger,must override the log method.
     *
     *  @param str String will be print.
     */
    virtual void log(const char* str) = 0;
};
#endif /* defined(__testproject__ILoger__) */
