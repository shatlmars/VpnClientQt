#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form();
    connect(ui->SettingsBut, &QPushButton::clicked, this, &MainWindow::openSecondForm);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openSecondForm()
{
    form->show();
}
