#include "car_dialog.h"
#include "ui_car_dialog.h"
#include "QDebug"

CarDialog::CarDialog(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::car_dialog),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

CarDialog::~CarDialog() {
    delete ui;
}

void CarDialog::on_acceptButton_clicked() {
    accept();
}

void CarDialog::on_rejectButton_clicked() {
    reject();
}

void CarDialog::on_buttonBox_accepted()
{
    QString brand = ui->brandLineEdit->text();
    QString model = ui->modelLineEdit->text();
    QString licensePlate = ui->licensePlateLineEdit->text();
    int distance = ui->distanceLineEdit->text().toInt();

    if (dbManager) {
        dbManager->addCar(brand, model, licensePlate, distance);
    }
}

