#include "ToDoList.h"
#include <fstream>
#include <iostream>

void ToDoList::addTask(const std::string task, int& taskCount)
{
    std::ofstream taskFile("tasks.txt", std::ios::app);
    taskFile << taskCount << ". " << task << '\n';
    taskFile.close();
    
    taskCount++;
}

void ToDoList::listTasks(const int taskCount)
{
    std::ifstream taskFile("tasks.txt");
    std::string task;

    for(int i = 0; i < taskCount; i++)
    {
        getline(taskFile, task);
        std::cout << task << '\n';
    }

    taskFile.close();
}

void ToDoList::clearTasks(int& taskCount)
{
    std::ofstream taskFile("tasks.txt", std::ios::trunc);
    taskFile.close();

    taskCount = 1;
}

void ToDoList::removeTask(const int taskId, int& taskCount)
{
    std::ifstream taskFile("tasks.txt");
    std::ofstream temp("temp.txt");
    std::string line;
    int trashInt;

    for(int i = 1; i < taskId; i++)
    {
        getline(taskFile, line);
        temp << line << '\n';
    }

    getline(taskFile, line);

    taskCount--;

    for(int i = taskId; i < taskCount; i++)
    {
        taskFile >> trashInt;
        getline(taskFile, line);
        temp << i << line << '\n';
    }

    taskFile.close();
    temp.close();

    std::remove("tasks.txt");
    std::rename("temp.txt", "tasks.txt");
}

void ToDoList::getTaskCount(int& taskCount)
{
    std::ifstream taskFile("tasks.txt");
    std::string line;
    taskCount = 0;

    while(getline(taskFile, line))
        taskCount++;

    taskCount++;

}