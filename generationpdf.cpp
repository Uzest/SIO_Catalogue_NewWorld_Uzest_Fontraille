/**
 * @author Alexia Fontraille & Nicolas Uzest
 * @date 11 septembre 2015
 * @file generationpdf.cpp
 */
#include "generationpdf.h"

//constructeur
Generationpdf::Generationpdf(QString n, QDate d)
{
    nom = n;
    dateGeneration = d;
}

Generationpdf::Generationpdf()
{
}

//Cette fonction va nous permettre d'écrire le texte dans le PDF
void Generationpdf::ecrireTexte(QString leTexte )
{

}

//Cette fonction va nous permettre de fermer le PDF
void Generationpdf::fermer()
{

}

