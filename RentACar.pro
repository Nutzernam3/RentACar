QT       += core gui widgets sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    car_dialog.cpp \
    customer_dialog.cpp \
    database_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    rental_dialog.cpp

HEADERS += \
    car_dialog.h \
    customer_dialog.h \
    database_manager.h \
    mainwindow.h \
    rental_dialog.h

FORMS += \
    car_dialog.ui \
    customer_dialog.ui \
    mainwindow.ui \
    rental_dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
