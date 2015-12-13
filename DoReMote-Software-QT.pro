QT += core
QT += gui
QT += bluetooth
QT += multimedia

LIBS += -luser32

TARGET = DoReMote-Software-QT
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp
