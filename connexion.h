#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QCoreApplication>
#include <QSqlQuery>
#include <QSqlRecord>
#include <cstdlib>
#include <iostream>


class Connexion
{
public:
    Connexion();
private:
    QSqlDatabase * baseCatalogue;
};

#endif // CONNEXION_H
