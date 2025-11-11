#include <fstream>
#include "Commands.h"
#include "ToDoListManagerModel.h"
#include "CommandParser.h"
#include "Task.hpp"

std::string AddTaskCommand::execute(ToDoListManagerModel& model)
{
    auto it = m_parsed.args.find("-name");
    if (it == m_parsed.args.end()) {
        return "Invalid flag for add_task. Use -name.";
    }

    const std::string& name = it->second;
    if (name.empty()) {
        return "Task name cannot be empty.";
    }

    Task task(name);
    model.addTask(std::move(task));
    return "";
}

std::string RemoveTaskCommand::execute(ToDoListManagerModel& model)
{
    auto it = m_parsed.args.find("-name");
    if (it == m_parsed.args.end()) {
        return "Invalid flag for remove_task. Use -name.";
    }

    const std::string& name = it->second;
    if (name.empty()) {
        return "Task name cannot be empty.";
    }

    model.removeTask(name);
    return "";
}

std::string CompleteTaskCommand::execute(ToDoListManagerModel& model)
{
    auto it = m_parsed.args.find("-name");
    if (it == m_parsed.args.end()) {
        return "Invalid flag for complete_task. Use -name.";
    }

    const std::string& name = it->second;
    if (name.empty()) {
        return "Task name cannot be empty.";
    }

    model.completeTask(name);
    return "";
}

std::string ListTasksCommand::execute(ToDoListManagerModel& model)
{
    model.listTask();
    return "";
}

std::string ExecuteFileCommand::execute(ToDoListManagerModel& model)
{
    auto it = m_parsed.args.find("-file_path");
    if (it == m_parsed.args.end()) {
        return "Invalid flag for execute_file. Use -file_path.";
    }

    const std::string& path = it->second;
    if (path.empty()) {
        return "File path cannot be empty.";
    }

    std::ifstream file(path);
    if (!file.is_open()) {
        return "Cannot open file: " + path;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty())
            continue;

        model.executeCommand(line);
    }

    return "Finished executing file: " + path;
}
