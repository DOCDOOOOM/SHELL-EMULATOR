#include "shell.h"
#include <sstream>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

std::string Shell::execute(const std::string &command)
{
    history.push_back(command);
    std::stringstream output;

    std::string fullCommand = "cmd /c " + command;
    FILE *pipe = _popen(fullCommand.c_str(), "r");

    if (!pipe)
    {
        output << "Failed to execute command.\n";
        return output.str();
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        std::string line(buffer);

        // Remove all trailing \n and \r characters
        while (!line.empty() && (line.back() == '\n' || line.back() == '\r'))
        {
            line.pop_back();
        }

        output << line << '\n';
    }

    _pclose(pipe);
    return output.str();
}
