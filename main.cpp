#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "ToDoList.h"

int main()
{
    std::string command, task;
    int taskCount, taskId;
    bool exit = false;
    std::ofstream taskFile("tasks.txt", std::ios::app);
    ToDoList list;

    list.getTaskCount(taskCount);

    std::cout << "Welcome to CLI To-Do List!" << '\n';
    std::cout << "Write help if you don't know the commands." << '\n';

    while (!exit)
    {

        std::cin >> command;

        if (command == "help")
        {
            std::cout << "Available commands:" << '\n';
            std::cout << "add - Add a new task" << '\n';
            std::cout << "list - List all tasks" << '\n';
            std::cout << "remove - Remove a task" << '\n';
            std::cout << "clear - Remove all tasks" << '\n';
            std::cout << "exit - Exit the application" << '\n';
        }
        else if (command == "add")
        {
            std::cout << "Enter the task description: ";
            std::cin.ignore();
            getline(std::cin, task);
            list.addTask(task, taskCount);
        }
        else if (command == "list")
        {
            list.listTasks(taskCount);
        }
        else if (command == "remove")
        {
            std::cout << "Enter the id task you want to remove: ";
            std::cin >> taskId;
            if(taskId > taskCount)
                std::cout << "The task you want to remove doesn't exist" << '\n';
            else
                list.removeTask(taskId, taskCount);
        }
        else if (command == "clear")
        {
            std::cout << "All tasks are gone." << '\n';
            list.clearTasks(taskCount);
        }
        else if (command == "exit")
        {
            exit = true;
            std::cout << "Exiting the application. Goodbye!" << '\n';
        }
        else
        {
            std::cout << "Unknown command. Type 'help' for a list of commands." << '\n';
        }
    }

    return 0;
}