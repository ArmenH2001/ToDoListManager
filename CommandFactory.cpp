#include "CommandFactory.h"

#include "Commands.h"

std::unique_ptr<ICommand> CommandFactory::create(const ParsedCommand& parsed,
                                                 std::string& errorMsg)
{
    errorMsg.clear();
    const std::string& command = parsed.name;

    if (command == "list_tasks") {
        if (!parsed.args.empty()) {
            errorMsg = "'list_tasks' command should not have arguments.";
            return nullptr;
        }
        return std::make_unique<ListTasksCommand>();
    }

    if (command == "execute_file") {
        if (parsed.args.empty()) {
            errorMsg = "'execute_file' requires flag and argument. "
                       "Example: execute_file -file_path {path}";
            return nullptr;
        }

        auto it = parsed.args.find("-file_path");
        if (parsed.args.size() != 1 || it == parsed.args.end()) {
            errorMsg = "'execute_file' accepts only '-file_path' flag.";
            return nullptr;
        }
        if (it->second.empty()) {
            errorMsg = "File path cannot be empty.";
            return nullptr;
        }

        return std::make_unique<ExecuteFileCommand>(parsed);
    }

    if (command == "add_task" ||
        command == "remove_task" ||
        command == "complete_task")
    {
        if (parsed.args.empty()) {
            errorMsg = "'" + command +
                       "' requires flag and argument. Example: " +
                       command + " -name {Task name}";
            return nullptr;
        }

        auto it = parsed.args.find("-name");
        if (parsed.args.size() != 1 || it == parsed.args.end()) {
            errorMsg = "Invalid flag. Use '-name'.";
            return nullptr;
        }

        if (it->second.empty()) {
            errorMsg = "Name in { } cannot be empty.";
            return nullptr;
        }

        if (command == "add_task")
            return std::make_unique<AddTaskCommand>(parsed);
        if (command == "remove_task")
            return std::make_unique<RemoveTaskCommand>(parsed);
        if (command == "complete_task")
            return std::make_unique<CompleteTaskCommand>(parsed);
    }

    errorMsg = "Unknown command: " + command;
    return nullptr;
}
