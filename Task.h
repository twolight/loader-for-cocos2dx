//
//  Task.h
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#ifndef __testproject__Task__
#define __testproject__Task__
#include "Statu.h"
#include "CountDownLatch.h"
typedef const std::function<void()> TaskRunnable;
class Task{
private:
    std::thread* _thread;
    TaskRunnable _runnable;
    bool _isCancel;
    Statu _statu;
    std::string _name;
    CountDownLatch* _doneSignal;
public:
    Task(const std::string& name,TaskRunnable& runnable);
    ~Task();
    void start();
    /**
     *  Description
     */
    void cancel();
    void setName(const std::string& name);
    std::string getName();
    void setDownSignal(CountDownLatch* _doneSignal);

};

#endif /* defined(__testproject__Task__) */
