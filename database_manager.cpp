#include "database_manager.h"

DatabaseManager::DatabaseManager(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
}

DatabaseManager::~DatabaseManager()
{
    closeConnection();
}

bool DatabaseManager::openConnection(const QString &dbName)
{
    db.setDatabaseName(dbName);

    if (!db.open()) {
        qDebug() << "Error: Failed to connect" << db.lastError().text();
        return false;
    }

    qDebug() << "Connected...";
    return true;
}

void DatabaseManager::closeConnection()
{
    if (db.isOpen()) {
        db.close();
    }
}

bool DatabaseManager::initializeTables()
{
    QSqlQuery query;

    // CUSTOMER
    bool success = query.exec("CREATE TABLE IF NOT EXISTS customers (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, address TEXT, phone TEXT)");
    if (!success) {
        qDebug() << "Error customers:" << query.lastError().text();
        return false;
    }

    // CARS
    success = query.exec("CREATE TABLE IF NOT EXISTS cars (id INTEGER PRIMARY KEY AUTOINCREMENT, brand TEXT, model TEXT, licensePlate TEXT, distance INTEGER)");
    if (!success) {
        qDebug() << "Error cars:" << query.lastError().text();
        return false;
    }

    // RENTS
    success = query.exec("CREATE TABLE IF NOT EXISTS rentals (id INTEGER PRIMARY KEY AUTOINCREMENT, customerId INTEGER, carId INTEGER, startDate TEXT, endDate TEXT, distance INTEGER, FOREIGN KEY(customerId) REFERENCES customers(id), FOREIGN KEY(carId) REFERENCES cars(id))");
    if (!success) {
        qDebug() << "Error rents:" << query.lastError().text();
        return false;
    }

    return true;
}

// ADDING CUSTOMER
bool DatabaseManager::addCustomer(const QString &name, const QString &address, const QString &phone)
{
    QSqlQuery query;
    query.prepare("INSERT INTO customers (name, address, phone) VALUES (:name, :address, :phone)");
    query.bindValue(":name", name);
    query.bindValue(":address", address);
    query.bindValue(":phone", phone);

    if (!query.exec()) {
        qDebug() << "Error customer:" << query.lastError().text();
        return false;
    }

    emit customerAdded();
    return true;
}

// ADDING CAR
bool DatabaseManager::addCar(const QString &brand, const QString &model, const QString &licensePlate, int &distance)
{
    QSqlQuery query;
    query.prepare("INSERT INTO cars (brand, model, licensePlate, distance) VALUES (:brand, :model, :licensePlate, :distance)");
    query.bindValue(":brand", brand);
    query.bindValue(":model", model);
    query.bindValue(":licensePlate", licensePlate);
    query.bindValue(":distance", distance);

    if (!query.exec()) {
        qDebug() << "Error car:" << query.lastError().text();
        return false;
    }

    emit carAdded();
    return true;
}

// ADDING RENTS
bool DatabaseManager::addRental(int customerId, int carId, const QDate &startDate, const QDate &endDate, int &distance)
{
    QSqlQuery query;
    query.prepare("INSERT INTO rentals (customerId, carId, startDate, endDate, distance) VALUES (:customerId, :carId, :startDate, :endDate, :distance)");
    query.bindValue(":customerId", customerId);
    query.bindValue(":carId", carId);
    query.bindValue(":startDate", startDate.toString(Qt::ISODate));
    query.bindValue(":endDate", endDate.toString(Qt::ISODate));
    query.bindValue(":distance", distance);

    if (!query.exec()) {
        qDebug() << "Error rents:" << query.lastError().text();
        return false;
    }

    emit rentalAdded();
    return true;
}
