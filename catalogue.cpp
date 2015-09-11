#include "catalogue.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlQuery>

catalogue::catalogue()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    maBase=new QSqlDatabase(db);
    maBase->setHostName("172.16.63.111");
    maBase->setDatabaseName("dbafontrailleNewWorld");
    maBase->setUserName("afontraille");
    maBase->setPassword("dTj124fs");
    bool ok = maBase->open();
}


