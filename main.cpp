/**
 * @author A Fontraille
 * @date 11 septembre 2015
 * @file main.cpp
 */
#include <QCoreApplication>
#include <QSqlDatabase>
#include <QtGui/QPrinter>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    //connexion a la base de données
    QSqlDatabase * baseCatalogue;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseCatalogue = new QSqlDatabase(db);
    baseCatalogue->setHostName("172.16.63.111");
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
    QCoreApplication a(argc, argv);


    return a.exec();
}
