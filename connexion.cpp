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
    //ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    baseCatalogue=new QSqlDatabase(db);
    baseCatalogue->setHostName("172.16.63.111");
    baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
    baseCatalogue->setUserName("afontraille");
    baseCatalogue->setPassword("dTj124fs");
    baseCatalogue->open();

}
