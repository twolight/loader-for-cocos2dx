//
//  Wave.h
//  testproject
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
};
#endif /* defined(__testproject__Wave__) */
