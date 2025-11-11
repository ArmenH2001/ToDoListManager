#pragma once
#include "ICommand.hpp"
#include "CommandParser.h" // ParsedCommand
#include <string>

class ToDoListManagerModel;

class AddTaskCommand : public ICommand
{
public:
    explicit AddTaskCommand(ParsedCommand parsed)
        : m_parsed(std::move(parsed))
    {}

    std::string name() const override { return "add_task"; }

    std::string execute(ToDoListManagerModel& model) override;

private:
    ParsedCommand m_parsed;
};

class RemoveTaskCommand : public ICommand
{
public:
    explicit RemoveTaskCommand(ParsedCommand parsed)
        : m_parsed(std::move(parsed))
    {}

    std::string name() const override { return "remove_task"; }

    std::string execute(ToDoListManagerModel& model) override;

private:
    ParsedCommand m_parsed;
};

class CompleteTaskCommand : public ICommand
{
public:
    explicit CompleteTaskCommand(ParsedCommand parsed)
        : m_parsed(std::move(parsed))
    {}

    std::string name() const override { return "complete_task"; }

    std::string execute(ToDoListManagerModel& model) override;

private:
    ParsedCommand m_parsed;
};

class ListTasksCommand : public ICommand
{
public:
    std::string name() const override { return "list_tasks"; }
    std::string execute(ToDoListManagerModel& model) override;
};

class ExecuteFileCommand : public ICommand
{
public:
    explicit ExecuteFileCommand(ParsedCommand parsed)
        : m_parsed(std::move(parsed))
    {}

    std::string name() const override { return "execute_file"; }

    std::string execute(ToDoListManagerModel& model) override;

private:
    ParsedCommand m_parsed;
};
