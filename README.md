# loader-for-cocos2dx
A init loader for cocos2dx(c++),also can be used in a c++ project.
# usage
Loader* loader = Loader::getInstance();\n
loader->setAutoDestroy(true);\n
loader->addTask(new Task("task1",[](){\n
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
