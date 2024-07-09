#ifndef CUSTOMER_DIALOG_H
#define CUSTOMER_DIALOG_H

#include <QDialog>
#include "database_manager.h"
#include "ui_customer_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CustomerDialog; }
QT_END_NAMESPACE

class CustomerDialog : public QDialog {
    Q_OBJECT

public:
    explicit CustomerDialog(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~CustomerDialog();

private slots:
    void on_acceptButton_clicked();
    void on_rejectButton_clicked();
    void on_buttonBox_accepted();

private:
    Ui::customer_dialog *ui;
    DatabaseManager *dbManager;
};

#endif // CUSTOMER_DIALOG_H
