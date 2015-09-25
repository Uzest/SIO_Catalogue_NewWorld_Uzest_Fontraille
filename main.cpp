/**
 * @author A Fontraille
 * @date 11 septembre 2015
 * @file main.cpp
 */
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QtGui/QPrinter>
#include <QString>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QDebug>

#include "connexion.h"


int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
/*
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFileName("Catalogue.pdf");

    QPainter painter(&printer);
    painter.begin(&printer);
    painter.setFont(QFont("Verdana",12));
    painter.drawText(200,200,"Catalogue New World");
    painter.end();

    return 0;*/
}
