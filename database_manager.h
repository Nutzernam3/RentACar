// database_manager.h

#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QtSql>

class DatabaseManager : public QObject {
    Q_OBJECT

public:
    explicit DatabaseManager(QObject *parent = nullptr);
    ~DatabaseManager();

    bool openConnection(const QString &dbName = "/Users/nutzername/Desktop/sqlite-tools-osx-x64-3460000/car_rental_db.sqlite");
    void closeConnection();
    bool initializeTables();

    bool addCustomer(const QString &name, const QString &address, const QString &phone);
    bool addCar(const QString &brand, const QString &model, const QString &licensePlate, int &distance);
    bool addRental(int customerId, int carId, const QDate &startDate, const QDate &endDate, int &distance);

private:
    QSqlDatabase db;

signals:
    void customerAdded();
    void carAdded();
    void rentalAdded();

};

#endif // DATABASEMANAGER_H
