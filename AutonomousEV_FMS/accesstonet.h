#ifndef ACCESSTONET_H
#define ACCESSTONET_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkProxy>
#include <QAuthenticator>

struct dataFromServer
{
    QByteArray bytedata;
};

class AccessToNet : public QObject
{
    Q_OBJECT
public:
    explicit AccessToNet(QObject *parent = nullptr);

    dataFromServer dataServer;

signals:

public slots:

    void get(QString location);
    void post(QString location, QByteArray data);

private slots:

    void readyRead();
    void authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator);
    void encrypted(QNetworkReply *reply);
    void finished(QNetworkReply *reply);
    void networkAccessibleChannged(QNetworkAccessManager::NetworkAccessibility accessible);
    void preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator);
    void proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

private:

    QNetworkAccessManager manager;

};

#endif // ACCESSTONET_H
