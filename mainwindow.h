#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlTableModel>
#include "database_manager.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(DatabaseManager *dbManager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onDataChanged();
    void on_addCustomerButton_clicked();
    void on_editCustomerButton_clicked();       // TODO
    void on_deleteCustomerButton_clicked();     // TODO

    void on_addCarButton_clicked();
    void on_editCarButton_clicked();            // TODO
    void on_deleteCarButton_clicked();          // TODO

    void on_addRentalButton_clicked();
    void on_viewRentalStatusButton_clicked();   // TODO

private:
    Ui::MainWindow *ui;
    DatabaseManager *dbManager;
    QSqlTableModel *customerModel;
    QSqlTableModel *carModel;
    QSqlTableModel *rentalModel;

    void setupModels();
};

#endif // MAINWINDOW_H
