#ifndef CAR_DIALOG_H
#define CAR_DIALOG_H

#include <QDialog>
#include "database_manager.h"
#include "ui_car_dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CarDialog; }
QT_END_NAMESPACE

class CarDialog : public QDialog {
    Q_OBJECT

public:
    explicit CarDialog(QWidget *parent = nullptr, DatabaseManager *dbManager = nullptr);
    ~CarDialog();

private slots:
    void on_acceptButton_clicked();
    void on_rejectButton_clicked();
    void on_buttonBox_accepted();

private:
    Ui::car_dialog *ui;
    DatabaseManager *dbManager;
};

#endif // CAR_DIALOG_H
