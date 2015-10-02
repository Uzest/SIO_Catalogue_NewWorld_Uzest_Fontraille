#include "produit.h"
#include <QDate>
#include <QSqlQuery>
//constructeur

Produit::Produit(int no, QString lib)
{
    noProduit = no;
    libelleProduit = lib;
}

Produit::Produit()
{

}

QString Produit::getLibelleProduit()
{
    QSqlQuery requeteLib;

    QString produitLibelle;

    requeteLib.prepare("Select libelleProd from produit where num=prodNum" "values(:libelleProd");

    requeteLib.bindValue(":libelleProd",produitLibelle);

    requeteLib.exec();

    return produitLibelle;

}

int Produit::getPrixUnitaireLot()
{
    QSqlQuery requetePrix;

    float lotPrix;

    requetePrix.prepare("Select prixLot from lot where noProduit=prodNum" "values(:prodLots");

    requetePrix.bindValue(":prodNum",lotPrix);

    requetePrix.exec();

    return lotPrix;

}

int Produit::getQuantiteLot()
{
    QSqlQuery requeteQte;

    int lotQte;

    requeteQte.prepare("Select qttMinimalLot from Lots where noProduit=prodNum" "values(:QteMin");

    requeteQte.bindValue(":QteMin",lotQte);

    requeteQte.exec();

    return lotQte;
}

QDate Produit::getDateLimiteConsomationLot()
{
    QSqlQuery requeteDate;

    QDate dateLimite;

    requeteDate.prepare("Select lotDateLimite from Lots" "values(:dateLimite");

    requeteDate.bindValue(":dateLimite",dateLimite);

    requeteDate.exec();


    return dateLimite;

}

