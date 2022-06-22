#include "accesstonet.h"

AccessToNet::AccessToNet(QObject *parent) : QObject(parent)
{
    connect(&manager, &QNetworkAccessManager::authenticationRequired, this, &AccessToNet::authenticationRequired);
    connect(&manager, &QNetworkAccessManager::encrypted, this, &AccessToNet::encrypted);
    connect(&manager, &QNetworkAccessManager::networkAccessibleChanged, this, &AccessToNet::networkAccessibleChannged);
    connect(&manager, &QNetworkAccessManager::preSharedKeyAuthenticationRequired, this, &AccessToNet::preSharedKeyAuthenticationRequired);
    connect(&manager, &QNetworkAccessManager::proxyAuthenticationRequired, this, &AccessToNet::proxyAuthenticationRequired);
    connect(&manager, &QNetworkAccessManager::sslErrors, this, &AccessToNet::sslErrors);

}

void AccessToNet::get(QString location)
{
//    qInfo() << "Getting from server...";
    QNetworkReply* reply = manager.get(QNetworkRequest(QUrl(location)));
    connect(reply, &QNetworkReply::readyRead, this, &AccessToNet::readyRead);

}

void AccessToNet::post(QString location, QByteArray data)
{
    qInfo() << "Posting to server...";
    QNetworkRequest request = QNetworkRequest(QUrl(location));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QNetworkReply* reply = manager.post(request, data);
    connect(reply, &QNetworkReply::readyRead, this, &AccessToNet::readyRead);

}

void AccessToNet::readyRead()
{
//    qInfo() << "Ready Read!";
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    if(reply)
    {
        dataServer.bytedata = reply->readAll();

    }
}

void AccessToNet::authenticationRequired(QNetworkReply *reply, QAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "authenticationRequired";
}

void AccessToNet::encrypted(QNetworkReply *reply)
{
    Q_UNUSED(reply);
//    qInfo() << "encrypted";
}

void AccessToNet::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "finished";
}

void AccessToNet::networkAccessibleChannged(QNetworkAccessManager::NetworkAccessibility accessible)
{
    Q_UNUSED(accessible);
    qInfo() << "networkAccessibleChannged";
}

void AccessToNet::preSharedKeyAuthenticationRequired(QNetworkReply *reply, QSslPreSharedKeyAuthenticator *authenticator)
{
    Q_UNUSED(reply);
    Q_UNUSED(authenticator);
    qInfo() << "preSharedKeyAuthenticationRequired";
}

void AccessToNet::proxyAuthenticationRequired(const QNetworkProxy &proxy, QAuthenticator *authenticator)
{
    Q_UNUSED(proxy);
    Q_UNUSED(authenticator);
    qInfo() << "proxyAuthenticationRequired";
}

void AccessToNet::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    Q_UNUSED(errors);
    qInfo() << "sslErrors";
}
