#ifndef ROOT_H
#define ROOT_H

#include <QWidget>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

namespace Ui {
class Root;
}

class Root : public QWidget
{
    Q_OBJECT

public:
    explicit Root(QWidget *parent = nullptr);
    ~Root();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Root *ui;
    QNetworkAccessManager* accessManager;

};

#endif // ROOT_H
