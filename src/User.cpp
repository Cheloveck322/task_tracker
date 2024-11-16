#include "../include/User.h"
#include "../include/TasksManager.h"
#include <iostream>

void User::setData(int argc, char* argv[])
{
    if (argc > 1)
    {
        m_command = argv[1];
        for (int i{ 2 }; i < argc; ++i)
        {
            m_parameters.push_back(argv[i]);
        }
    }
}

void User::run()
{
    if (m_command.empty())
    {
        std::cout << "There's no command specified.\n";
    }
    else 
    {
        TasksManager taskManager{};

        if (m_command == "add")                     taskManager.addTask(m_parameters[0]);
        else if (m_command == "update")             taskManager.updateTask(std::stoi(m_parameters[0]), m_parameters[1]);
        else if (m_command == "delete")             taskManager.deleteTask(std::stoi(m_parameters[0]));
        else if (m_command == "mark-in-progress")   taskManager.markInProgress(std::stoi(m_parameters[0]));
        else if (m_command == "mark-done")          taskManager.markDone(std::stoi(m_parameters[0]));
        else if (m_command == "mark-todo")          taskManager.markTodo(std::stoi(m_parameters[0]));
        else if (m_command == "clear")              taskManager.clear();
        else if (m_command == "list")   
        {
            if (m_parameters.empty())
            {
                taskManager.list();
            }
            else
            {
                taskManager.list(m_parameters[0]);
            }
        }
        else    std::cout << "There isn't this command. Try enter: add, update, delete, mark-in-progress, mark-done, list.\n";
    }
}