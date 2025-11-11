#pragma once

#include <QWidget>

class QVBoxLayout;
class QScrollArea;
class TaskItemWidget;

class TaskListDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit TaskListDisplay(QWidget* parent = nullptr);

    void clear();
    void addTask(const std::string& name, const bool complated);
private:
    QVBoxLayout* m_mainLayout;
    QList<TaskItemWidget*> m_taskList;
};

