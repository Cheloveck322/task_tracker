#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

class User
{
public:
    User() = default;
    
    void setData(int argc, char* argv[]); 

    void run();

    const std::string& getCommand() const { return m_command; }

    const std::vector<std::string>& getParameters() const { return m_parameters; }

private: 
    std::string m_command{};
    std::vector<std::string> m_parameters{};
};

#endif