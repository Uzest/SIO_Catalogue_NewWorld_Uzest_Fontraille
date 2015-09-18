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
    Generationpdf();
    QString nom;
    QDate dateGeneration;

private:
     Generationpdf(QString n, QDate d);
     void ecrireTexte(QString leTexte);
};

#endif // GENERATIONPDF_H
