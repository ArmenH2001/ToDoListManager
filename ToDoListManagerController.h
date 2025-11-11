#pragma once
#include <QObject>
#include "ToDoListManagerViewWidget.h"
#include "ToDoListManagerModel.h"

class ToDoListManagerController : public QObject
{
    Q_OBJECT
public:
    static ToDoListManagerController& instance();

    int run(QApplication &app);

private:
    explicit ToDoListManagerController(QObject* parent = nullptr);

    ToDoListManagerController(const ToDoListManagerController&) = delete;
    ToDoListManagerController& operator=(const ToDoListManagerController&) = delete;
    ToDoListManagerController(ToDoListManagerController&&) = delete;
    ToDoListManagerController& operator=(ToDoListManagerController&&) = delete;

private:
    void makeConnections();

private:
    ToDoListManagerViewWidget* m_mainWindow;
    ToDoListManagerModel* m_viewModel;
};

