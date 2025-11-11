#include "ToDoListManagerController.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ToDoListManagerController& controller = ToDoListManagerController::instance();
    return controller.run(app);
}
