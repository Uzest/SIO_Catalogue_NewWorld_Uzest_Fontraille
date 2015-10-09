/**
 * @author Alexia Fontraille & Nicolas Uzest
 * @file generationpdf.h
 * @date 11 septembre 2015
 */
#ifndef GENERATIONPDF_H
#define GENERATIONPDF_H
#include <QString>
#include <iostream>
#include <QDate>

class Generationpdf
{
public:

    QString nom;
    QDate dateGeneration;

    Generationpdf();
    Generationpdf(QString n, QDate d);
    //Ecrire le texte du PDF
    void ecrireTexte(QString leTexte);
    //Fermer le texte du PDF
    void fermer();
};

#endif // GENERATIONPDF_H

