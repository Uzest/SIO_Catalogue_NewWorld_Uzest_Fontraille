#ifndef PDF_H
#define PDF_H
#include <QString>

class Pdf
{
public:
    Pdf();
    int idPdf;
    QString nom;

private:
     Pdf(int id, QString n);
};

#endif // PDF_H
