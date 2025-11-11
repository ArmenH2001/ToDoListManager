#pragma once
#include <string>

class ToDoListManagerModel;

class ICommand
{
public:
    virtual ~ICommand() = default;
    virtual std::string name() const = 0;
    virtual std::string execute(ToDoListManagerModel& model) = 0;
};

