#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <QSqlDatabase>
#include <QTextCodec>

class catalogue
{
public:
    catalogue();


private:
Ui::Produit *ui;
QSqlDatabase * baseCatalogue;

};

#endif // CATALOGUE_H
