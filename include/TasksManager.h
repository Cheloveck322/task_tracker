#ifndef TASKS_MANAGER_H
#define TASKS_MANAGER_H

#include <vector>
#include <string>
#include "Task.h"
#include "util.h"

class TasksManager
{
public:
    TasksManager();

    void addTask(const std::string& descript);

    void updateTask(unsigned id, const std::string& newDescript);

    void deleteTask(unsigned id);

    void markInProgress(unsigned id);

    void markDone(unsigned id);

    void markTodo(unsigned id);

    void list();

    void list(const std::string& status);

    void clear();

private:
    const char* const m_jsonFileName{};
};

#endif 