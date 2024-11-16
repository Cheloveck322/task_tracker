#include "../include/util.h"
#include <chrono>
#include <ctime>
#include <iomanip>
#include <fstream>

void writeTaskToJson(const Task& task, const std::string& filename)
{
    std::ifstream jsonFile{ filename };
    std::string jsonContent{ std::istreambuf_iterator<char>(jsonFile), std::istreambuf_iterator<char>() };
    jsonFile.close();

    size_t beginTask{ jsonContent.find_last_of('[', + 1) };
    size_t endTask{ jsonContent.find_last_of(']') };

    std::string newTask
    {
        "\n    {\n"
        "        \"id\": " + std::to_string(task.id) + ",\n"
        "        \"description\": \"" + task.descript + "\",\n"
        "        \"status\": \"" + task.status + "\",\n"
        "        \"createdAt\": \"" + task.createdAt + "\",\n"
        "        \"updatedAt\": \"" + task.updatedAt + "\"\n"
        "    }\n"
    };

    if (beginTask != std::string::npos && endTask != std::string::npos)
    {
        jsonContent.insert(endTask, ", " + newTask);
    }
    else 
    {
        jsonContent = "[" + newTask + "]";
    }

    std::ofstream json{ filename, std::ios::trunc };
    json << jsonContent;
    json.close();
}

std::vector<Task> getTasksFromJson(const std::string& filename)
{
    std::vector<Task> tasks{};

    std::ifstream jsonFile{ filename };
    std::string jsonContent{ std::istreambuf_iterator<char>(jsonFile), std::istreambuf_iterator<char>() };
    jsonFile.close();

    size_t beginTask{ jsonContent.find('[') + 1 };
    size_t endTask{ jsonContent.find_last_of(']') };

    if (beginTask != std::string::npos && endTask != std::string::npos)
    {
        std::string tasksJson{ jsonContent.substr(beginTask, endTask - beginTask) };

        size_t taskBeginPos{};
        size_t taskEndPos{ tasksJson.find('}') };

        while (taskEndPos != std::string::npos)
        {
            std::string taskJson{ tasksJson.substr(taskBeginPos, taskEndPos - taskBeginPos + 1) };

            Task task{};

            size_t idBeginPos{ taskJson.find("\"id\": ") + 6 };
            size_t idEndPos{ taskJson.find(',', idBeginPos) };
            task.id = std::stoi(taskJson.substr(idBeginPos, idEndPos - idBeginPos));

            size_t descriptBeginPos{ taskJson.find("\"description\": \"") + 16 };
            size_t descriptEndPos{ taskJson.find('\"', descriptBeginPos) };
            task.descript = taskJson.substr(descriptBeginPos, descriptEndPos - descriptBeginPos);

            size_t statusBeginPos{ taskJson.find("\"status\": \"") + 11 };
            size_t statusEndPos{ taskJson.find('\"', statusBeginPos) };
            task.status = taskJson.substr(statusBeginPos, statusEndPos - statusBeginPos);

            size_t createdBeginPos{ taskJson.find("\"createdAt\": \"") + 14 };
            size_t createdEndPos{ taskJson.find('\"', createdBeginPos) };
            task.createdAt = taskJson.substr(createdBeginPos, createdEndPos - createdBeginPos);

            size_t updatedBeginPos{ taskJson.find("\"updatedAt\": \"") + 14 };
            size_t updatedEndPos{ taskJson.find('\"', updatedBeginPos) };
            task.updatedAt = taskJson.substr(updatedBeginPos, updatedEndPos - updatedBeginPos);

            tasks.push_back(task);

            taskBeginPos = taskEndPos + 1;
            taskEndPos = tasksJson.find('}', taskBeginPos);
        }
    }

    return tasks;
}

unsigned getNextId(const std::string& filename)
{
    std::vector<Task> tasks{ getTasksFromJson(filename) };

    unsigned maxId{};

    for (const auto& task : tasks)
    {
        if (maxId < task.id)
        {
            maxId = task.id;
        }
    }

    return maxId;
}

std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&nowTimeT);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    std::string currentTime = oss.str();
    return currentTime;
}