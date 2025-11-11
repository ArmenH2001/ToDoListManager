#include "ToDoListManagerModel.h"
#include "CommandParser.h"
#include "CommandFactory.h"
#include "ICommand.hpp"

#include <utility>

ToDoListManagerModel::ToDoListManagerModel(QObject* parent)
    : QObject(parent)
{
}

void ToDoListManagerModel::executeCommand(const std::string& commandStr)
{
    CommandParser parser;
    ParsedCommand parsed;
    std::string errorMsg;

    if (!parser.parse(commandStr, parsed, errorMsg)) {
        emit log(errorMsg);
        return;
    }

    std::unique_ptr<ICommand> cmd = CommandFactory::create(parsed, errorMsg);
    if (!cmd) {
        emit log(errorMsg);
        return;
    }

    auto msg = cmd->execute(*this);
    if (!msg.empty())
        emit log(msg);
}

void ToDoListManagerModel::addTask(Task task)
{
    const std::string& name = task.name();
    auto it = m_taskMap.find(name);
    if (it != m_taskMap.end()) {
        emit log("Task already exists: " + name);
        return;
    }

    m_taskMap.emplace(name, std::move(task));
    emit log("Task added: " + name);
}

void ToDoListManagerModel::removeTask(const std::string& name)
{
    std::size_t erased = m_taskMap.erase(name);
    if (erased == 0) {
        emit log("Task not found: " + name);
    } else {
        emit log("Task removed: " + name);
    }
}

void ToDoListManagerModel::completeTask(const std::string& name)
{
    auto it = m_taskMap.find(name);
    if (it == m_taskMap.end()) {
        emit log("Task not found: " + name);
        return;
    }

    if (!it->second.isCompleted()) {
        it->second.complete();
        emit log("Task completed: " + name);
    } else {
        emit log("Task already completed: " + name);
    }
}

void ToDoListManagerModel::listTask()
{
    emit requestClearTaskList();

    if (m_taskMap.empty()) {
        emit log("No tasks.");
        return;
    }

    for (const auto& pair : m_taskMap) {
        const std::string &name = pair.first;
        const Task& t = pair.second;
        emit task(name, t.isCompleted());
    }
    emit log("Tasks listed.");
}
