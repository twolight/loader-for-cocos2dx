//
//  ILoger.h
//  testproject
//
//  Created by twolight on 15-10-24.
//
//

#ifndef __testproject__ILoger__
#define __testproject__ILoger__

class ILoger{
public:
    virtual ~ILoger(){};
    virtual void log(const char* str,...) = 0;
};
#endif /* defined(__testproject__ILoger__) */
