#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include "Task.h"

void writeTaskToJson(const Task& task, const std::string& filename);

std::vector<Task> getTasksFromJson(const std::string& filename);

unsigned getNextId(const std::string& filename);

std::string getCurrentTime();

#endif 