# loader-for-cocos2dx
A init loader for cocos2dx(c++),also can be used in a c++ project.
# usage
```c++
  Loader* loader = Loader::getInstance();
  loader->setAutoDestroy(true);
  loader->addTask(new Task("task1",[](){
  	std::this_thread::sleep_for(std::chrono::milliseconds(200));
  }), 1);
  loader->addTask(new Task("task2",[](){
  	std::this_thread::sleep_for(std::chrono::milliseconds(900));
  }), 1);
  loader->addTask(new Task("task3",[](){
  	std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }), 2);
  loader->addTask(new Task("task4",[](){
  	std::this_thread::sleep_for(std::chrono::milliseconds(400));
  }), 3);
  loader->start();
```
#Contact
Welocme to send pull request.please contact twolight@163.com
