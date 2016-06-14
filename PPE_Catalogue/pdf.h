#ifndef PDF_H
#define PDF_H
#include <QSqlDatabase>
#include <QString>
//#include <QtGui/QPrinter>
#include <QPrintDialog>
#include <QPrinter>
#include <QtGui/QPainter>
#include <QPrintEngine>
//#include <QtGui/QPrintEngine>
#include <QDebug>
#include <QSqlQuery>
#include <iostream>

class Pdf
{
public:
    Pdf();
    void start();

private:
    QPainter _painter;
    QPrinter *_printer;

    int _top;

    void drawDistributors(QString userId);
    void drawLot(QString distributorId);


    void databaseConnect();
    void setBold(bool value);
    void setFont(int size, QString police = "Times New Roman");
    void setFontColor(QString color);
    void drawImage(QString url, int x, int y, int width, int height);
    void calcAddPage();
    void addPage();
};

#endif // PDF_H
