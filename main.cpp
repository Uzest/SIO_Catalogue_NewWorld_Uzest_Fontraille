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

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    /**
     * @brief db
     * Connexion à la base de données
     */
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("172.16.63.111");
    db.setDatabaseName("dbafontrailleNewWorld");
    db.setUserName("afontraille");
    db.setPassword("dTj124fs");
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



    QSqlQuery queryPdv("select libelle, activite, nom, prenom, rue1, rue2, CP, tel, email, CP, localites from pointDeVente");
    int cpt=0;

    while (queryPdv.next())
    {

        painter.setFont(QFont("Verdana",12));
        painter.drawText(50,900+cpt*500,"-");
        //Ressors le libellé
        QString libelle=queryPdv.value(0).toString();
        painter.drawText(120,900+cpt*500,libelle);
        //Ressors l'activité
        QString activite=queryPdv.value(1).toString();
        painter.drawText(2000,900+cpt*500,activite);
        //Ressors le nom
        QString nom=queryPdv.value(2).toString();
        painter.drawText(3500,900+cpt*500,nom);
        //Ressors le prénom
        QString prenom=queryPdv.value(3).toString();
        painter.drawText(4200,900+cpt*500,prenom);
        //Ressors le téléphone
        QString tel=queryPdv.value(4).toString();
        painter.drawText(5200,900+cpt*500,tel);
        //Ressors l'email
        QString email=queryPdv.value(5).toString();
        painter.drawText(7000,900+cpt*500,email);
        //Ressors la rue1
        QString rue1=queryPdv.value(6).toString();
        painter.drawText(300,1150+cpt*500,rue1);
        //Ressors la rue2
        QString rue2=queryPdv.value(7).toString();
        painter.drawText(1000,1150+cpt*500,rue2);
        //Ressors le CP
        QString CP=queryPdv.value(8).toString();
        painter.drawText(2500,1150+cpt*500,CP);
        //Ressors la ville
        QString ville=queryPdv.value(9).toString();
        painter.drawText(4700,1150+cpt*500,ville);

        cpt++;

    }

        painter.setFont(QFont("Verdana",15));
        painter.drawText(50,900+cpt*800,"Liste des Produits");


        QSqlQuery queryDistribution("select ");
        painter.end();

    return 0;
}
