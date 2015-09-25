#ifndef TYPEPRODUIT_H
#define TYPEPRODUIT_H

#include "rayon.h"
class TypeProduit
{
private:
    int no;
    QString libelleType;
public:
    TypeProduit(int n, QString l);
    TypeProduit();
    QString getLibelleTypeProduit();
    int getNoTypeProduit();
};

#endif // TYPEPRODUIT_H
