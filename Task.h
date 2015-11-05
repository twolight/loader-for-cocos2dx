//
//  Task.h
//  loader-for-cocos2dx
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
    /**
     *  Task start.
     */
    void start();
    /**
     *  Set a unique name for task
     *
     *  @param name Name string.
     */
    void setName(const std::string& name);
    /**
     *  Get task's name.
     *
     *  @return return Task name string.
     */
    std::string getName();
    /**
     *  Task set a signal in order to notify the wave when the task finish.
     *
     *  @param _doneSignal CountDownLatch Object.
     */
    void setDownSignal(CountDownLatch* _doneSignal);

};

#endif /* defined(__testproject__Task__) */
