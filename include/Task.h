#ifndef TASK_H
#define TASK_H

#include <string>

struct Task
{
    Task() = default;
    Task(unsigned newId, std::string newDescript);

    unsigned id{};
    std::string descript{};
    std::string status{};
    std::string createdAt{};
    std::string updatedAt{};

    void print() const;
};

#endif