/**
 * @author A Fontraille
 * @date 11 septembre 2015
 * @file main.cpp
 */
#include <QApplication>
#include <QSqlDatabase>
#include <QString>
#include <QtGui/QPrinter>
#include <QtGui/QPainter>
#include <QtGui/QPrintEngine>
#include <QDebug>

#include "connexion.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("172.16.63.111");
    //baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
    //baseCatalogue->setUserName("afontraille");
    //baseCatalogue->setPassword("dTj124fs");
    db.setDatabaseName("dbnuzestNewWorld");
    db.setUserName("nuzest");
    db.setPassword("bsIve12W6");
    db.open();

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFileName("/tmp/Catalogue.pdf");

    QPainter painter;
    painter.begin(&printer);

    painter.setFont(QFont("Verdana",30));
    painter.drawText(50,200,"Catalogue New World");
    painter.setFont(QFont("Verdana",15));
    painter.drawText(50,600,"Liste des Points de ventes");



    QSqlQuery queryPdv("select pdvLibelle, pdvTel, pdvMail, pdvRue1, pdvRue2 from PtsDeVente");
    int cpt=0;

    while (queryPdv.next())
    {

        painter.setFont(QFont("Verdana",12));
        painter.drawText(50,900+cpt*500,"-");
        QString pdvLibelle=queryPdv.value(0).toString();
        painter.drawText(120,900+cpt*500,pdvLibelle);
        QString pdvTel=queryPdv.value(1).toString();
        painter.drawText(2000,900+cpt*500,pdvTel);
        QString pdvMail=queryPdv.value(2).toString();
        painter.drawText(3500,900+cpt*500,pdvMail);
        QString pdvRue1=queryPdv.value(3).toString();
        painter.drawText(300,1100+cpt*500,pdvRue1);
        QString pdvRue2=queryPdv.value(4).toString();
        painter.drawText(2500,1100+cpt*500,pdvRue2);

        cpt++;

    }

        painter.setFont(QFont("Verdana",15));
        painter.drawText(50,900+cpt*800,"Liste des Produits");
        painter.end();

    return 0;
}
