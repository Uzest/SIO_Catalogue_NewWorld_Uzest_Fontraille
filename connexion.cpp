/**
 * @author Nicolas Uzest
 * @date 18 septembre 2015
 * @file connexion.cpp
 * @brief Connexion à la BDD
 */

#include "connexion.h"
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>
#include <iostream>

using namespace std;

Connexion::Connexion()
{
    //connexion a la base de données
    //QSqlDatabase * baseCatalogue;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseCatalogue = new QSqlDatabase(db);
    baseCatalogue->setHostName("172.16.63.111");
    /*baseCatalogue->setUserName("nuzest");
    baseCatalogue->setDatabaseName("dbnuzestNewWorld");
    baseCatalogue->setPassword("BsIve12W6");*/
    baseCatalogue->setUserName("afontraille");
    baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
    baseCatalogue->setPassword("dTj124fs");
    bool ok = baseCatalogue->open();

    if(!ok)
    {
       qDebug() << "La base de données est connectée";
    }
    else
    {
        qDebug() << "La connexion a échoué";
    }
}
