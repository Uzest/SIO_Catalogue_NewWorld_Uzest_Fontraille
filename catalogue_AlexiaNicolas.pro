#-------------------------------------------------
#
# Project created by QtCreator 2015-09-11T14:59:31
#
#-------------------------------------------------

QT       += core
QT       -= gui
QT       += sql
QT       += printsupport

TARGET = catalogue_AlexiaNicolas
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    generationpdf.cpp \
    produit.cpp \
    rayon.cpp \
    typeproduit.cpp \
    connexion.cpp

HEADERS += \
    generationpdf.h \
    produit.h \
    rayon.h \
    typeproduit.h \
    connexion.h
