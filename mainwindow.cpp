#include "mainwindow.h"
#include "ui_mainwindow.h"

ModMaker::ModMaker(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ModMaker)
{
    ui->setupUi(this);
}

ModMaker::~ModMaker()
{
    delete ui;
}

