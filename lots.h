/**
 * @author Alexia Fontraille
 * @date 11 septembre 2015
 * @file lots.h
 * @brief permet de générer les lots
 */
#ifndef LOTS_H
#define LOTS_H

#include <QSqlDatabase>
#include <QTextCodec>

class Lots
{
public:
    Lots();


private:
QSqlDatabase * baseCatalogue;

};

#endif // LOTS_H
