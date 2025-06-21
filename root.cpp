#include "root.h"
#include "ui_root.h"

Root::Root(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Root)
{
    ui->setupUi(this);
    accessManager = new QNetworkAccessManager();
}

Root::~Root()
{
    delete ui;
}

void Root::on_pushButton_clicked()
{
    QUrl url("https://google.com");
    QNetworkRequest request(url);
    QNetworkReply *reply = accessManager->get(request);

    connect(reply, &QNetworkReply::finished, [=](){
        if(reply->error() == QNetworkReply::NoError){
            QByteArray byteArr = reply->readAll();
            qDebug() << byteArr;
        }else{
            qDebug() << "Error: " << reply->errorString();
        }

        reply->deleteLater();
        accessManager->deleteLater();
    });
}

