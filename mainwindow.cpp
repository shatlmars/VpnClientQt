#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form();
    rootForm = new Root();
    QShortcut *openRoot = new QShortcut(QKeySequence("Ctrl+N"), this);
    QShortcut *closeProgram = new QShortcut(QKeySequence("Alt+Ctrl+Q"), this);
    connect(ui->SettingsBut, &QPushButton::clicked, this, &MainWindow::openSecondForm);
    connect(openRoot, &QShortcut::activated, this, &MainWindow::openRoot);
    connect(closeProgram, &QShortcut::activated, this, &MainWindow::closeProgram);
}

MainWindow::~MainWindow()
{
    rootForm->close();
    form->close();
    delete rootForm;
    delete form;
    delete ui;
}

void MainWindow::openSecondForm()
{
    form->show();
}

void MainWindow::openRoot()
{
    rootForm->show();
}

void MainWindow::closeProgram()
{
    delete this;
}
