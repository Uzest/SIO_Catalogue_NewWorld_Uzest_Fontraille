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

    int horizontale=300;
    int verticale=3500;

    QSqlQuery queryPdv("select libelle, activite, nom, prenom, tel, email, rue1, rue2, CP, CP, localites from pointDeVente");
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
        painter.drawText(1700,1150+cpt*500,rue2);
        //Ressors le CP
        QString CP=queryPdv.value(8).toString();
        painter.drawText(4000,1150+cpt*500,CP);
        //Ressors la ville
        QString ville=queryPdv.value(9).toString();
        painter.drawText(6000,1150+cpt*500,ville);

        cpt++;

    }
        //###################RAYON = SURTYPE#######################

        //###########################RAYONS########################
        QSqlQuery queryRayon;
        queryRayon.exec("select no, libelleSurType from surType");
        while(queryRayon.next())
        {
              //définis la couleur
              painter.setPen(QColor(255,0,50,200));
              //Définis le texte
              painter.setFont(QFont("Verdana",15));
              QString noRayon=queryRayon.value(0).toString();
              QString libelle=queryRayon.value(1).toString();
              QString qtProd="Quantite";
              QString prixProd="Prix";
              QString modeProdProduit="Production";
              QString dateRecolte="date de recolte";
              QString jourConservationProd="Conservation";
              painter.drawText(300,verticale,"Rayon: "+libelle);
              verticale=verticale+300;
              painter.setFont(QFont("Verdana",10));
              painter.drawText(3800,verticale,qtProd);
              painter.drawText(4700,verticale,prixProd);
              painter.drawText(5400,verticale,modeProdProduit);
              painter.drawText(6400,verticale,dateRecolte);
              painter.drawText(7700,verticale,jourConservationProd);

              //##################PRODUIT##############################
              QSqlQuery queryTypeProduit;
              queryTypeProduit.exec("select no, libelleType from type where noSurType=" + QString(noRayon));
              while(queryTypeProduit.next())
              {
                  painter.setFont(QFont("Verdana",12));
                  QString libelleProd=queryTypeProduit.value(0).toString();
                  QString noProd=queryTypeProduit.value(1).toString();
                  //################METTRE L'IMAGE ICI#############
                  /*QImage img(libelleType+".png");
                  img.load(libelleType+".png");
                  painter.drawImage(QPoint(1000,verticale+100),img);
                  painter.drawRect(700,verticale-200,8100,900);
                  painter.drawText(1000,verticale,libTypeProduit);
                  verticale=verticale+300;*/

                  QSqlQuery queryProduit;
                  queryProduit.exec("select libelleProd, num from produit where noType=" + QString(noProd));
                  while(queryProduit.next())
                  {
                      painter.setFont(QFont("Verdana",12));
                      QString libelleProd=queryProduit.value(0).toString();
                      QString noProd=queryProduit.value(1).toString();
                      painter.drawText(2200,verticale,libelleProd);
                      QSqlQuery queryLot("select qttMinimaleLot, prixLot, uniteMesure, modeProductionLot, dateLot, nbJourConservationLot, from lot where no="+ QString(noProd));
                      while(queryLot.next())
                      {
                          QString qttLot=queryLot.value(0).toString();
                          QString prixLot=queryLot.value(1).toString();
                          QString uniteMesure=queryLot.value(2).toString();
                          QString modeProdLot=queryLot.value(3).toString();
                          QString dateLot=queryLot.value(4).toString();
                          QString nbJourConservation=queryLot.value(5).toString();
                          painter.setFont(QFont("Tahoma",9));
                          painter.drawText(4200,verticale,qttLot);
                          painter.drawText(4800,verticale,prixLot+"€ / "+uniteMesure);
                          painter.drawText(5800,verticale,modeProdLot);
                          painter.drawText(6800,verticale,dateLot);
                          painter.drawText(8000,verticale,nbJourConservation+" jours");
                      }
                      verticale=verticale+300;
                  }
              }
              verticale=verticale+200;
        }



        //QSqlQuery queryDistribution();
        painter.end();

    return 0;
}
