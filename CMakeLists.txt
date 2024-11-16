cmake_minimum_required(VERSION 3.13)
project(task_tracker)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES 
    src/main.cpp
    src/Task.cpp
    src/TasksManager.cpp
    src/User.cpp
    src/util.cpp
)

include_directories(include)

add_executable(task_tracker ${SOURCES})

target_include_directories(task_tracker PRIVATE ${PROJECT_SOURCE_DIR}/include)