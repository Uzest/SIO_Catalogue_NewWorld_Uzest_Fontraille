#include <QCoreApplication>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    //connexion a la base de données
    QSqlDatabase * baseCatalogue;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    baseCatalogue = new QSqlDatabase(db);
    baseCatalogue->setHostName("172.16.63.111");
    baseCatalogue->setUserName("afontraille");
    baseCatalogue->setDatabaseName("dbafontrailleNewWorld");
    baseCatalogue->setPassword("dTj124fs");
    baseCatalogue->open();
    QCoreApplication a(argc, argv);


    return a.exec();
}
