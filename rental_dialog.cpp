#include "rental_dialog.h"
#include "ui_rental_dialog.h"
#include <QDebug>

RentalDialog::RentalDialog(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::rental_dialog),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

RentalDialog::~RentalDialog() {
    delete ui;
}

void RentalDialog::on_acceptButton_clicked() {
    accept();
}

void RentalDialog::on_rejectButton_clicked() {
    reject();
}

void RentalDialog::on_buttonBox_accepted()
{
    int customerID = ui->customerSpinBox->value();
    int carID = ui->carSpinBox->value();
    QDate startDate = ui->fromDateEdit->date();
    QDate endDate = ui->toDateEdit->date();
    int distance = ui->distancelineEdit->text().toInt();

    if (dbManager) {
        dbManager->addRental(customerID, carID, startDate, endDate, distance);
    }
}


