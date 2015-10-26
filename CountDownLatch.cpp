//
//  CountDownLatch.cpp
//  testproject
//
//  Created by twolight on 15-10-25.
//
//

#include "CountDownLatch.h"

CountDownLatch::CountDownLatch(int count):
_count(count),
_mutex(),
_condition(){
    
}
void CountDownLatch::countDown(){
    std::unique_lock<std::mutex> lock(_mutex);
    _count--;
    if(_count == 0){
        _condition.notify_all();
    }
}
int CountDownLatch::getCount(){
    std::unique_lock<std::mutex> lock(_mutex);
    return _count;
}
void CountDownLatch::wait(){
    std::unique_lock<std::mutex> lock(_mutex);
    while(_count > 0){
        _condition.wait(lock);
    }
}