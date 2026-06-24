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
    char trashPoint;
    bool deleted = false;

    for(int i = 1; i < taskCount; i++)
    {
        if(i != taskId || deleted)
        {
            taskFile >> trashInt;
            taskFile >> trashPoint;
            getline(taskFile, line);
            std::cout << line << '\n';
            temp << i << '.' << line << '\n';
        }
        else
        {
            taskFile >> trashInt;
            taskFile >> trashPoint;
            getline(taskFile, line);
            i--;
            deleted = true;
        }

    }

    taskCount--;

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

    if(taskFile)
    {
          while(getline(taskFile, line))
            taskCount++;
    }
    else
    {
        taskCount = 1;
    }

}