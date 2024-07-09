#ifndef RENTAL_DIALOG_H
#define RENTAL_DIALOG_H

#include <QDialog>
#include "database_manager.h"
#include "ui_rental_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RentalDialog; }
QT_END_NAMESPACE

class RentalDialog : public QDialog {
    Q_OBJECT

public:
    explicit RentalDialog(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~RentalDialog();

private slots:
    void on_acceptButton_clicked();
    void on_rejectButton_clicked();
    void on_buttonBox_accepted();

private:
    Ui::rental_dialog *ui;
    DatabaseManager *dbManager;
};

#endif // RENTAL_DIALOG_H
