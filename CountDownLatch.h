//
//  CountDownLatch.h
//  testproject
//
//  Created by twolight on 15-10-25.
//
//

#ifndef __testproject__CountDownLatch__
#define __testproject__CountDownLatch__

class CountDownLatch{
private:
    std::mutex _mutex;
    std::condition_variable _condition;
    int _count;
public:
    CountDownLatch(int count);
    void countDown();
    int getCount();
    /**
     *  Current thread wait until _count equal 0.
     */
    void wait();
};
#endif /* defined(__testproject__CountDownLatch__) */
