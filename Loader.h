//
//  Loader.h
//  testproject
//
//  Created by twolight on 15-10-22.
//
//

#ifndef __testproject__Loader__
#define __testproject__Loader__
#include "Wave.h"
#include "ILoger.h"
#include <vector>
#include <string>
class Loader{
private:
    static Loader* _instance;
    std::vector<Wave*> _waves;
    Statu _statu;
    Loader();
    ~Loader();
public:
    static Loader* getInstance();
    static void destroy();
    /**
     *  Add a task to Loader.
     *  
     *  @param taskName
     *  @param task The Task.
     *  @param wave Task's wave index.
     *
     *  @return Loader point.
     */
    Loader* addTask(const std::string& taskName,Task* task,unsigned wave);
    
    /**
     *  Cancel a task by taskName.
     *
     *  @param TaskId Task ID.
     */
    void cancelTask(const std::string& taskName);
    
    /**
     *  Loader start.
     */
    void clearTask();
    void start();
    void setLoger(ILoger* loger);
    
   
    
};
#endif /* defined(__testproject__Loader__) */
