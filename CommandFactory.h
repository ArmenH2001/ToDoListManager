#pragma once

#include <memory>
#include <string>
#include "CommandParser.h"

class ICommand;

class CommandFactory
{
public:
    static std::unique_ptr<ICommand> create(const ParsedCommand& parsed,
                                            std::string& errorMsg);
};
