#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customer_dialog.h"
#include "car_dialog.h"
#include "rental_dialog.h"

MainWindow::MainWindow(DatabaseManager *dbManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , dbManager(dbManager)
{
    ui->setupUi(this);
    setupModels();

    /// SIGNAL-SLOT CONNETIONS
    connect(dbManager, &DatabaseManager::customerAdded, this, &MainWindow::onDataChanged);
    connect(dbManager, &DatabaseManager::carAdded, this, &MainWindow::onDataChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Update model
void MainWindow::onDataChanged()
{
    int currentIndex = ui->tabWidget->currentIndex();
    switch (currentIndex) {
    case 0: // Customers Tab
        customerModel->select();
        break;
    case 1: // Cars Tab
        carModel->select();
        break;
    case 2: // Rentals Tab
        rentalModel->select();
        break;
    default:
        break;
    }
}

/// Customer
void MainWindow::on_addCustomerButton_clicked()
{
    CustomerDialog dialog(this, dbManager);
    if (dialog.exec() == QDialog::Accepted) {
        customerModel->select();
    }
}

void MainWindow::on_editCustomerButton_clicked()
{
    // TODO: edit
}

void MainWindow::on_deleteCustomerButton_clicked()
{
    // TODO: del
}

/// Car
void MainWindow::on_addCarButton_clicked()
{
    CarDialog dialog(this, dbManager);
    if (dialog.exec() == QDialog::Accepted) {
        carModel->select();
    }
}

void MainWindow::on_editCarButton_clicked()
{
    // TODO: edit
}

void MainWindow::on_deleteCarButton_clicked()
{
    // TODO: del
}

/// Rents
void MainWindow::on_addRentalButton_clicked()
{
    RentalDialog dialog(this, dbManager);
    dialog.exec();
}

void MainWindow::on_viewRentalStatusButton_clicked()
{
    // TODO: view
}

/// Model
void MainWindow::setupModels()
{
    // Customer
    customerModel = new QSqlTableModel(this);
    customerModel->setTable("customers");
    customerModel->select();

    // Customer view
    ui->customerTableView->setModel(customerModel);
    ui->customerTableView->hideColumn(0);
    ui->customerTableView->resizeColumnsToContents();

    // Car
    carModel = new QSqlTableModel(this);
    carModel->setTable("cars");
    carModel->select();

    // Car view
    ui->carTableView->setModel(carModel);
    ui->carTableView->hideColumn(0);
    ui->carTableView->resizeColumnsToContents();

    // Rents
    rentalModel = new QSqlTableModel(this);
    rentalModel->setTable("rentals");
    rentalModel->select();

    // Rents view
    ui->rentalTableView->setModel(rentalModel);
    ui->rentalTableView->hideColumn(0);
    ui->rentalTableView->resizeColumnsToContents();

    // signal Tab changeing
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onDataChanged);
}
