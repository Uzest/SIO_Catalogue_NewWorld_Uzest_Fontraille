/**
 * @author Alexia Fontraille
 * @date 11 septembre 2015
 * @file catalogue.cpp
 * @brief permet de générer le catalogue
 */
#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <QSqlDatabase>
#include <QTextCodec>

class catalogue
{
public:
    catalogue();


private:
Ui::Produit  *ui;
QSqlDatabase * baseCatalogue;

};

#endif // CATALOGUE_H
