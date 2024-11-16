#include <iostream>
#include "../include/User.h"
#include "../include/Task.h"
#include "../include/util.h"

int main(int argc, char* argv[])
{
    User user;

    user.setData(argc, argv);

    user.run();

    return 0;
}