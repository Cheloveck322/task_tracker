#include "../include/Task.h"
#include "../include/util.h"
#include <iostream>

Task::Task(unsigned newId, std::string newDescript)
          : id{ newId }, descript{ newDescript }, status{ "todo" }, 
            createdAt{ getCurrentTime() }, updatedAt{ getCurrentTime() }
{
}

void Task::print() const
{
    std::cout << "\"id\": " << id << ",\n";
    std::cout << "\"description\": \"" << descript << "\",\n";
    std::cout << "\"status\": \"" << status << "\",\n";
    std::cout << "\"createdAt\": \"" << createdAt << "\",\n";
    std::cout << "\"updatedAt\": \"" << updatedAt << "\"\n";
    std::cout << '\n';
}