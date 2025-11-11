#include "ToDoListManagerController.h"
#include <QApplication>
ToDoListManagerController::ToDoListManagerController(QObject* parent)
    : QObject(parent),
    m_mainWindow(new ToDoListManagerViewWidget()),
    m_viewModel(new ToDoListManagerModel())
{
    makeConnections();
}

void ToDoListManagerController::makeConnections()
{
    connect(m_mainWindow, &ToDoListManagerViewWidget::executeCommand,
            m_viewModel, &ToDoListManagerModel::executeCommand);
    connect(m_viewModel, &ToDoListManagerModel::log,
            m_mainWindow, &ToDoListManagerViewWidget::printLog);
    connect(m_viewModel, &ToDoListManagerModel::requestClearTaskList,
            m_mainWindow, &ToDoListManagerViewWidget::clearTaskList);
    connect(m_viewModel, &ToDoListManagerModel::task,
            m_mainWindow, &ToDoListManagerViewWidget::printTask);
}

ToDoListManagerController& ToDoListManagerController::instance()
{
    static ToDoListManagerController s_instance;
    return s_instance;
}

int ToDoListManagerController::run(QApplication& app)
{
    m_mainWindow->setWindowTitle("Qt App with MainController");
    m_mainWindow->resize(800, 600);
    m_mainWindow->show();

    return app.exec();
}
