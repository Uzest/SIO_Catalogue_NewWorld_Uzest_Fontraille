/**
 * @author Alexia Fontraille & Nicolas Uzest
 * @file generationpdf.h
 * @date 11 septembre 2015
 */
#ifndef GENERATIONPDF_H
#define GENERATIONPDF_H
#include <QString>

class Generationpdf
{
public:
    Generationpdf();
    int idPdf;
    QString nom;

private:
     Generationpdf(int id, QString n);
};

#endif // GENERATIONPDF_H
