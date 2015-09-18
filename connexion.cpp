#include "connexion.h"
#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlRecord>
#include <cstdlib>
#include <iostream>

using namespace std;

Connexion::Connexion()
{
//connexion a la base de données
//QSqlDatabase * baseCatalogue;
QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
baseCatalogue = new QSqlDatabase(db);
baseCatalogue->setHostName("172.16.63.111");
baseCatalogue->setUserName("afontraille");
baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
baseCatalogue->setPassword("dTj124fs");
bool ok = baseCatalogue->open();

if(!ok)
{
    cout << "La base de données est connectée"<<endl;
}
else
{
    cout << "La connexion a échoué"<<endl;
}
}
