#include "aboutform.h"
#include "ui_aboutform.h"

AboutForm::AboutForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AboutForm)
{
    ui->setupUi(this);
}

AboutForm::~AboutForm()
{
    delete ui;
}

void AboutForm::on_pushButton_clicked()
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

