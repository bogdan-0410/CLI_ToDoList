#ifndef ToDoList_h

#include <string>
#include <fstream>

#define ToDoList_h


class ToDoList
{
    public:
        void addTask(const std::string task, int& taskCount);
        void listTasks(const int taskCount);
        void clearTasks(int& taskCount);
        void removeTask(const int taskId, int& taskCount);
        void getTaskCount(int& taskCount);
};


#endif