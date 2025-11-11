#include "ToDoListManagerViewWidget.h"

#include <QLabel>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QBoxLayout>

#include "TaskListDisplay.h"
#include <iostream>
ToDoListManagerViewWidget::ToDoListManagerViewWidget(QWidget* parent)
    : QWidget(parent),
    m_taskDisplayTitleLabel (new QLabel("Tasks:")),
    m_logDisplayTitleLabel (new QLabel("Log:")),
    m_logDisplay (new QTextEdit()),
    m_taskListDisplay (new TaskListDisplay()),
    m_commandLine (new QLineEdit()),
    m_executeButton (new QPushButton("Execute"))

{
    setupMembers();
    setupLayout();
    makeConnections();
}

ToDoListManagerViewWidget::~ToDoListManagerViewWidget()
{
}

void ToDoListManagerViewWidget::setupMembers()
{
    m_logDisplay->setReadOnly(true);
}

void ToDoListManagerViewWidget::setupLayout(){
    QVBoxLayout* mainLayout = new QVBoxLayout();
    setLayout(mainLayout);

    mainLayout->addWidget(m_taskDisplayTitleLabel);
    mainLayout->addWidget(m_taskListDisplay);
    mainLayout->addWidget(m_logDisplayTitleLabel);
    mainLayout->addWidget(m_logDisplay);

    QHBoxLayout* commandLineLayout = new QHBoxLayout();
    mainLayout->addLayout(commandLineLayout);

    commandLineLayout->addWidget(m_commandLine);
    commandLineLayout->addWidget(m_executeButton);
}

void ToDoListManagerViewWidget::makeConnections()
{
    connect(m_executeButton, &QPushButton::clicked, this, [this](){
        emit executeCommand(m_commandLine->text().toStdString());
    });
}


void ToDoListManagerViewWidget::printLog(const std::string &log)
{
    m_logDisplay->append(QString::fromStdString(log));
}

void ToDoListManagerViewWidget::clearTaskList()
{
    m_taskListDisplay->clear();
}

void ToDoListManagerViewWidget::printTask(const std::string& name, bool complated)
{
    m_taskListDisplay->addTask(name, complated);
}
