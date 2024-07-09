#include "customer_dialog.h"
#include "ui_customer_dialog.h"
#include "QDebug"

CustomerDialog::CustomerDialog(QWidget *parent, DatabaseManager *dbManager) :
    QDialog(parent),
    ui(new Ui::customer_dialog),
    dbManager(dbManager)
{
    ui->setupUi(this);
}

CustomerDialog::~CustomerDialog() {
    delete ui;
}

void CustomerDialog::on_acceptButton_clicked() {
    accept();
}

void CustomerDialog::on_rejectButton_clicked() {
    reject();
}

void CustomerDialog::on_buttonBox_accepted()
{
    QString name = ui->nameLineEdit->text();
    QString address = ui->adressLineEdit->text();
    QString phone = ui->phoneLineEdit->text();

    if (dbManager){
        dbManager->addCustomer(name, address, phone);
    }
}

