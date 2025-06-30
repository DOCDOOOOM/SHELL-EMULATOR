#ifndef SHELL_H
#define SHELL_H

#include <string>
#include <vector>

class Shell {
public:
    std::vector<std::string> history;
    std::string execute(const std::string& command);
};

#endif
