//
//  Wave.h
//  loader-for-cocos2dx
//
//  Created by twolight on 15-10-22.
//
//

#ifndef __testproject__Wave__
#define __testproject__Wave__
#include "Task.h"
class Wave{
private:
    std::vector<Task*> _tasks;
    bool _isCancel;
public:
    Wave();
    ~Wave();
    /**
     *  Add task to the wave.
     *
     *  @param task
     */
    void addTask(Task* task);
    /**
     *  Start wave.
     */
    void start();
    /**
     *  Cancel wave.
     */
    void cancel();
};
#endif /* defined(__testproject__Wave__) */
