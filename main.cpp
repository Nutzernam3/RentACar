#include <QApplication>
#include "mainwindow.h"
#include "database_manager.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);


    DatabaseManager dbManager;
    if (!dbManager.openConnection()) {
        return 1;
    }

    if (!dbManager.initializeTables()){
        return 1;
    }

    MainWindow mainWindow(&dbManager);
    mainWindow.show();

    return app.exec();
}
