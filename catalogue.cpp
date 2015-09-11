/**
 * @author Alexia Fontraille
 * @date 11 septembre 2015
 * @file catalogue.cpp
 * @brief permet de générer le catalogue
 */
#include "catalogue.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>

catalogue::catalogue(int id, Qstring rayon, Qstring type, Qstring produit, Qstring libelle, float prix, int qte, Qdate dateLimite)
{
    idLots=id;
    rayonLots=rayon;
    typeLots=type;
    produitLots=produit;
    libelleLots=libelle;
    prixLots=prix;
    qteLots=qte;
    dateLimiteLots=dateLimite;
}


