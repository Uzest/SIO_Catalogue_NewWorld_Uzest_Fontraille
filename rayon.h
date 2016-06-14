/**
 * @author Alexia Fontraille
 * @date 11 septembre 2015
 * @file rayon.h
 */
#ifndef RAYON_H
#define RAYON_H
#include <QString>
#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlRecord>
#include <QSqlQuery>
#include <QTableView>
#include <QSqlRecord>

class Rayon
{
private:
    // Numéro du rayon
    int noSurType;
    // Libelle du rayon
    QString libelleSurType;

public:
    // Constructeur
    Rayon(int no, QString lib);
    Rayon();

    // Retourne le libellé du rayon
    QString getLibelleSurType();

    // Retourne le numéro du rayon
    int getNoSurType();

};
#endif // RAYON_H
