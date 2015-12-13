QT += core
QT += gui
QT += bluetooth
QT += multimedia

win:LIBS += -luser32

TARGET = DoReMote-Software-QT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    device.cpp \
    deviceinfo.cpp \
    characteristicinfo.cpp \
    serviceinfo.cpp

HEADERS += \
    device.h \
    deviceinfo.h \
    characteristicinfo.h \
    serviceinfo.h
