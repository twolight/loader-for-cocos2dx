//
//  Loader.h
//  loader-for-cocos2dx
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
#include <future>
class Loader{
private:
    static Loader* _instance;
    std::map<int,Wave*> _waves;
    Statu _statu;
    bool _autoDestroy;
    std::future<void> _future;
    Loader();
    ~Loader();
public:
    static Loader* getInstance();
    /**
     *  Destory loader object and release the resource.
     */
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
    Loader* addTask(Task* task,unsigned wave);
    
    /**
     *  Cancel a wave by index.
     *
     *  @param waveIndex Wave index.
     */
    void cancelWave(int waveIndex);
    
    /**
     *  Loader start.
     */
    void clearTask();
    /**
     *  Loader start work.
     */
    void start();
    /**
     *  Set a loger
     *
     *  @param loger A custom loger.
     */
    void setLoger(ILoger* loger);
    /**
     *  Get Loader's statu.
     *
     *  @return Loader's statu.
     */
    Statu getStatu();
    /**
     *  Set Loader whether is destroyed by itself after has done.
     *
     *  @param autoDestroy
     */
    void setAutoDestroy(bool autoDestroy);
   
    
};
#endif /* defined(__testproject__Loader__) */
