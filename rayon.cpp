/**
 * @author Alexia Fontraille
 * @date 11 septembre 2015
 * @file rayon.cpp
 */
#include "rayon.h"
#include <QSqlRecord>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QString>
#include <QDate>

//Constructeur du rayon
Rayon::Rayon(int no, QString lib)
{
    noSurType=no;
    libelleSurType=lib;

    //On récupère les champs dans la BDD
    QSqlQuery requeteSurType;
    requeteSurType.exec("SELECT noSurType, libelleSurType FROM surType");
    while(requeteSurType.next())
    {
        int noSurType = requeteSurType.value(0).toInt();
        QString libelleSurType = requeteSurType.value(1).toString();
    }
}

// Constructeur vide
Rayon::Rayon()
{
}

//Cette fonction retourne le numéro du surType (du rayon)
int Rayon::getNoSurType()
{
    return noSurType;
}

//Cette fonction retourne le libellé du surType (du rayon)
QString Rayon::getLibelleSurType()
{
    return libelleSurType;
}
