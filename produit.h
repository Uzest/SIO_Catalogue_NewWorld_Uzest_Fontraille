#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QDate>
#include <iostream>

using namespace std;

/**
* @class Classe Produit
* @brief Classe représentant le produit
* Private :
* nom du produit
* libelle du produit
* Public :
* Constructeur Produit
* @fn getLibelleProduit
* @brief retourne le libelle du produit
* @fn getPrixUnitaireLot
* @brief retourne la prix unitaire du produit
* @fn getQuantiteLot
* @brief retourne la quantite du lot
* @fn getDateLimiteConsomationLot
* @brief retourne la date limite de consomation
*/

class Produit {
private:
 int noProduit;
QString libelleProduit;
public:
//constructeur
Produit(int no, QString lib);
Produit();
//retourne le libelle du produit
QString getLibelleProduit();
//retourne le prix unitaire du produit
int getPrixUnitaireLot();
//retourne la quantité du lot
int getQuantiteLot();
 //retourne la date limite de consommation
QDate getDateLimiteConsomationLot();
};
#endif // PRODUIT_H
