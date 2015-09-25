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
#include <QMessageBox>

using namespace std;

Connexion::Connexion()
{
    ui->setupUi(this);
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    baseCatalogue=new QSqlDatabase(db);
    baseCatalogue->setHostName("172.16.63.111");
    baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
    baseCatalogue->setUserName("afontraille");
    baseCatalogue->setPassword("dTj124fs");
    bool ok = baseCatalogue->open();
    if(!ok)
    {
        QMessageBox::warning(this,"New World BackOffice","La connexion à la base de données a échoué\nVeuillez vérifier que le service mysql est lancé sur localhost",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok);
    }



    /*QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseCatalogue = new QSqlDatabase(db);
    baseCatalogue->setHostName("172.16.63.111");
    baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
    baseCatalogue->setUserName("afontraille");
    baseCatalogue->setPassword("dTj124fs");
    bool ok = baseCatalogue->open();

    if(!ok)
    {
       qDebug() << "La base de données est connectée";
    }
    else
    {
        qDebug() << "La connexion a échoué";
    }*/
}
