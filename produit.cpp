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

QString::getLibelleProduit()
{
    QSqlQuery requeteLib;

    requeteLib.prepare("Select libelleProd from produit where num=prodNum" "values(:prodNum");

    requeteLib.bindValue(":prodNum",produitNumero);

    requeteLib.exec();

    return produitLibelle;

}

int::getPrixUnitaireLot()
{
    QSqlQuery requetePrix;

    requetePrix.prepare("Select prixLot from lot where noProduit=prodNum" "values(:prodNum");

    requetePrix.bindValue(":prodNum",produitNumero);

    requetePrix.exec();

    return lotPrix;

}

int::getQuantiteLot()
{
    QSqlQuery requeteQte;

    requetearepare("Select prixLot from lot where noProduit=prodNum" "values(:prodNum");

    requetePrix.bindValue(":prodNum",produitNumero);

    requetePrix.exec();

    return lotPrix;
}

QDate::getDateLimiteConsomationLot()
{

}

