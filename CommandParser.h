#pragma once

#include <string>
#include <map>

struct ParsedCommand
{
    std::string name;
    std::map<std::string, std::string> args;
};

class CommandParser
{
public:
    bool parse(const std::string& input,
               ParsedCommand& outCommand,
               std::string& errorMsg);

private:
    static std::string trim(const std::string& s);
};
