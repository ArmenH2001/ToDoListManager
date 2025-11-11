#include "TaskListDisplay.h"

#include <QVBoxLayout>
#include <QScrollArea>
#include "TaskItemWidget.h"
#include <iostream>
TaskListDisplay::TaskListDisplay(QWidget* parent)
    : QWidget(parent)
{
    auto scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    auto container = new QWidget(scrollArea);
    m_mainLayout = new QVBoxLayout(container);
    m_mainLayout->setContentsMargins(0, 0, 0, 0);

    scrollArea->setWidget(container);

    auto outerLayout = new QVBoxLayout(this);
    outerLayout->setContentsMargins(0, 0, 0, 0);
    outerLayout->addWidget(scrollArea);
    setLayout(outerLayout);
}

void TaskListDisplay::clear()
{
    for(auto item : m_taskList){
        item->deleteLater();
    }
    m_taskList.clear();
}

void TaskListDisplay::addTask(const std::string& name, const bool complated)
{
    auto newItem = new TaskItemWidget(name, complated);
    m_taskList.append(newItem);
    m_mainLayout->addWidget(newItem);
}
