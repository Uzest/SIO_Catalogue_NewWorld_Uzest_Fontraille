/**
 * @author Alexia Fontraille
 * @date 11 septembre 2015
 * @file lots.cpp
 * @brief permet de générer les lots
 */
#include "lots.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <QDate>

Lots::Lots(int id, QString rayon, QString type, QString produit, QString libelle, float prix, int qte, QDate dateLimite)
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



