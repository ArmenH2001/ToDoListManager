#pragma once
#include <QObject>
#include <map>
#include "Task.hpp"

class ICommand;
class CommandParser;

class ToDoListManagerModel : public QObject
{
    Q_OBJECT
public:
    explicit ToDoListManagerModel(QObject* parent = nullptr);

signals:
    void log(const std::string&);
    void requestClearTaskList();
    void task(const std::string&, bool);

public slots:
    void executeCommand(const std::string& commandStr);

public:
    void addTask(Task task);
    void removeTask(const std::string& name);
    void completeTask(const std::string& name);
    void listTask();

private:
    std::map<std::string, Task> m_taskMap;
};
