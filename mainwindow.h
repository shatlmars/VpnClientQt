#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QShortcut>
#include "form.h"
#include "root.h"
#include "aboutform.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openSecondForm();
    void openRoot();
    void closeProgram();
private:
    Ui::MainWindow *ui;
    Form *form;
    Root* rootForm;
};
#endif // MAINWINDOW_H
