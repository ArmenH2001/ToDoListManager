#pragma once
#include <QWidget>

class QLabel;
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;

class TaskListDisplay;

class ToDoListManagerViewWidget : public QWidget
{
    Q_OBJECT

public:
    ToDoListManagerViewWidget(QWidget* parent = nullptr);
    ~ToDoListManagerViewWidget();
signals:
    void executeCommand(const std::string&);
public slots:
    void printLog(const std::string&);
    void clearTaskList();
    void printTask(const std::string& name, bool complated);
private:
    void setupMembers();
    void setupLayout();
    void makeConnections();
    void executeCommandSlot(const std::string&);
private:
    QLabel* m_taskDisplayTitleLabel;
    QLabel* m_logDisplayTitleLabel;
    QTextEdit* m_logDisplay;
    TaskListDisplay* m_taskListDisplay;
    QLineEdit* m_commandLine;
    QPushButton* m_executeButton;
};
