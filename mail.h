#ifndef MAIL_H
#define MAIL_H

#include <QTcpSocket>
#include <QString>
#include <QTextStream>

class Mail : public QObject
{
    Q_OBJECT


public:
    Mail( const QString &from, const QString &to,
    const QString &subject, const QString &body );
    ~Mail();

signals:
    void status( const QString &);

private slots:
    void readyRead();

private:
    QString message;
    QTextStream *t;
    QTcpSocket *socket;
    QString from;
    QString rcpt;
    QString response;
    enum states{Rcpt,Email,Data,Init,Body,Quit,Close};
    int state;

};
#endif // MAIL_H
