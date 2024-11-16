#include "../include/TasksManager.h"
#include "../include/Task.h"
#include <iostream>
#include <cstdio>

TasksManager::TasksManager()
        : m_jsonFileName{ "tasks.json" }
    {
    }

void TasksManager::addTask(const std::string& descript)
{
    Task task{ getNextId(m_jsonFileName) + 1, descript}; 

    writeTaskToJson(task, m_jsonFileName);
}

void TasksManager::updateTask(unsigned id, const std::string& newDescript)
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };
    std::remove(m_jsonFileName);

    for (auto& task : tasks)
    {
        if (task.id == id)
        {
            task.descript = newDescript;
            task.updatedAt = getCurrentTime();
        }
    }

    for (const auto& task : tasks)
    {
        writeTaskToJson(task, m_jsonFileName);
    }
}

void TasksManager::deleteTask(unsigned id)
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };
    std::remove(m_jsonFileName);

    for (const auto& task : tasks)
    {
        if (task.id != id)
        {
            writeTaskToJson(task, m_jsonFileName);
        }
    }
}

void TasksManager::markInProgress(unsigned id)
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };
    std::remove(m_jsonFileName);

    for (auto& task : tasks)
    {
        if (task.id == id)
        {
            task.status = "in-progress";
            task.updatedAt = getCurrentTime();
        }
    }    

    for (const auto& task : tasks)
    {
        writeTaskToJson(task, m_jsonFileName);
    }
}

void TasksManager::markDone(unsigned id)
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };
    std::remove(m_jsonFileName);

    for (auto& task : tasks)
    {
        if (task.id == id)
        {
            task.status = "done";
            task.updatedAt = getCurrentTime();
        }
    }

    for (const auto& task : tasks)
    {
        writeTaskToJson(task, m_jsonFileName);
    }
}

void TasksManager::markTodo(unsigned id)
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };
    std::remove(m_jsonFileName);

    for (auto& task : tasks)
    {
        if (task.id == id)
        {
            task.status = "todo";
            task.updatedAt = getCurrentTime();
        }
    }

    for (const auto& task : tasks)
    {
        writeTaskToJson(task, m_jsonFileName);
    }
}

void TasksManager::list()
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };

    for (const auto& task : tasks)
    {
        task.print();
    }
}

void TasksManager::list(const std::string& status)
{
    std::vector<Task> tasks{ getTasksFromJson(m_jsonFileName) };

    for (const auto& task : tasks)
    {
        if (task.status == status)
        {
            task.print();
        }
    }
}

void TasksManager::clear()
{
    std::remove(m_jsonFileName);
}