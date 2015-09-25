/**
 * @author: Alexia Fontraille
 * @file: typeProduit.cpp
 * @date: 25/09/15
 */

#include "typeproduit.h"

TypeProduit::TypeProduit(int n, QString l)
{
    no = n;
    libelleType = l;
    QSqlQuery requeteTP;
    requeteTP.exec("SELECT no, libelleType FROM type");
    while(requeteTP.next())
    {
        int no = requeteTP.value(0).toInt();
        QString libelleType = requeteTP.value(1).toString();
    }
}

TypeProduit::TypeProduit()
{

}

//Cette fonction retourne le libellé du type du produit
QString TypeProduit::getLibelleTypeProduit()
{
    return libelleType;
}

//Cette fonction retourne le numéro du type du produit
int TypeProduit::getNoTypeProduit()
{
    return no;
}
