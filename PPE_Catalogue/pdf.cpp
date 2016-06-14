#include "pdf.h"

using namespace std;

Pdf::Pdf()
{
    databaseConnect();
}

//connexion à la base de donnée
void Pdf::databaseConnect(){

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("127.0.0.1");
    db.setDatabaseName("newWorld2");
    db.setUserName("root");
    db.setPassword("");
    db.open();
}

void Pdf::start(){
    QSqlQuery queryUsers("SELECT * FROM users WHERE type=1");
    while(queryUsers.next()){
        QString userId = queryUsers.value(0).toString();
        QString firstname = queryUsers.value(1).toString();

        QPrinter printer(QPrinter::HighResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setFullPage(QPrinter::A4);

        printer.setOutputFileName("catalogues/" + userId  + "_catalogue.pdf");
        _printer = &printer;
        _top = 800;

        _painter.begin(_printer);

        setFont(60, "Comic Sans MS");
        _painter.drawText(0, _top, "NewWorld!");

        setFont(12);
        _top += 300;
        _painter.drawText(100, _top, "Bonjour " + firstname + " ! Voici votre catalogue...");

        // Dessin le logo
        drawImage("logo.jpg", 5700, 500, 3500, 3500);
        drawDistributors(userId);

        _painter.end();
    }
}

void Pdf::drawDistributors(QString userId){

    _top += 1300;
    QSqlQuery queryDistributor("SELECT * FROM distributor WHERE user=" + userId);
    while(queryDistributor.next()){
        if(queryDistributor.at() > 0)
            addPage();

        QString distributorId = queryDistributor.value(0).toString();
        QString firstname = queryDistributor.value(1).toString();
        QString lastname = queryDistributor.value(2).toString();
        QString phone = queryDistributor.value(6).toString();
        QString email = queryDistributor.value(3).toString();

        QString name = queryDistributor.value(4).toString();
        QString address = queryDistributor.value(7).toString();
        QString address2 = queryDistributor.value(8).toString();
        QString postalcode = queryDistributor.value(9).toString();

        _painter.drawRect(500, _top-200, 5000, 2100);
        setFontColor("#354b9a");
        setFont(10);

        setBold(true);
        _painter.drawText(700, _top, "Responsable:");
        setBold(false);

        _top += 200;
        _painter.drawText(700, _top, firstname + " " + lastname);
        _top += 200;
        _painter.drawText(700, _top, phone);
        _top += 200;
        _painter.drawText(700, _top, email);
        _top += 400;

        setBold(true);
        _painter.drawText(700, _top, "Point de vente:");
        setBold(false);

        _top += 200;
        _painter.drawText(700, _top, "Nom: " + name);
        _top += 200;
        _painter.drawText(700, _top, "Adresse: " + address);
        _top += 200;
        _painter.drawText(700, _top, "Complèment: " + address2);
        _top += 200;
        _painter.drawText(700, _top, "Code postal: " + postalcode);

        drawLot(distributorId);
    }
}

void Pdf::drawLot(QString distributorId){
    QString prevShelf("");
    QString prevCategory("");


    QSqlQuery queryProduct("SELECT "
                           "shelf.libelle,"
                           "category.libelle,"
                           "product.libelle,"
                           "product.picture,"
                           "lot.quantity,"
                           "lot.harvestDate,"
                           "lot.daysPreserve,"
                           "productionMode.libelle,"
                           "lot.price "

                           "FROM product"
                               " INNER JOIN lot ON lot.product = product.id"
                               " INNER JOIN productionmode ON lot.productionMode = productionMode.id"
                               " INNER JOIN category ON product.category = category.id"
                               " INNER JOIN shelf ON category.shelf = shelf.id"
                               " WHERE lot.pointOfSale=" + distributorId);
    while(queryProduct.next()){
        QString shelf = queryProduct.value(0).toString();
        QString category = queryProduct.value(1).toString();
        QString product = queryProduct.value(2).toString();
        QString picture = queryProduct.value(3).toString();
        QString quantity = queryProduct.value(4).toString();
        QString harvestDate = queryProduct.value(5).toString();
        QString daysPreserve = queryProduct.value(6).toString();
        QString productionMode = queryProduct.value(7).toString();
        QString price = queryProduct.value(8).toString();

        if(prevShelf != shelf || prevCategory != category){
            setBold(true);
            if(prevShelf != shelf){
                // Draw line shelf
                setFont(20);
                _painter.drawText(1000, _top + 600, shelf);
                _painter.drawLine(700, _top + 700, 9000,_top + 700);

                prevShelf = shelf;
                _top += 700;
            }

            // Draw line category and header
            setFont(12);
            _painter.drawText(1300, _top + 350, category);
            _top += 800;
            _painter.drawText(1300, _top, "Nom du produit");
            _painter.drawText(3000, _top, "Mode de prod.");
            _painter.drawText(4700, _top, "Date de récolte");
            _painter.drawText(6400, _top, "Conservation");
            _painter.drawText(8100, _top, "Quantité");
            _painter.drawText(9800, _top, "Prix");

            setBold(false);
            prevCategory = category;
            _top += 100;
        }


        // Draw product
        _painter.drawRect(680, _top-20, 535, 540);
        drawImage(picture, 700, _top, 500, 500);
        _top += 380;
        _painter.drawText(1300, _top, product);
        _painter.drawText(3000, _top, productionMode);
        _painter.drawText(4700, _top, harvestDate);
        _painter.drawText(6400, _top, daysPreserve);
        _painter.drawText(8100, _top, quantity);
        _painter.drawText(9800, _top, price);

        _top += 250;
        calcAddPage();
    }
}




void Pdf::setFont(int size, QString police){
    QFont font = QFont(police, size);
    font.setBold(true);
    _painter.setFont(font);
}

void Pdf::setBold(bool value){
    QFont font = _painter.font();
    font.setBold(value);
    _painter.setFont(font);
}

void Pdf::setFontColor(QString color){

    _painter.setPen(QColor(color));
}

void Pdf::calcAddPage(){
    if(_top > 12500)
    {
        addPage();
    }
}

void Pdf::addPage()
{
    _printer->newPage();
    _top = 500;
}

void Pdf::drawImage(QString url, int x, int y, int width, int height){
    QRectF rectangle(x, y, width, height);
    QImage image;
    image.load(url);
    _painter.drawImage(rectangle, image);
}
