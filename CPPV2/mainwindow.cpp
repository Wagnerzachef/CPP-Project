#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    addtea = new addTea();
    addbeverage = new addBeverage();
    addcoffee = new addCoffee();
    addother = new other();
    lookup = new lookUp();

    QSqlDatabase DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/sqlite/CPPproject.v1.db");
    if (DB_Connection.open()) {
        qDebug() << "Database is connected";
    } else {
        qDebug() << "Database is not connected";
        qDebug() << "Error: " << DB_Connection.lastError();
    }
}

MainWindow::~MainWindow()         //deletes the ui when the window is closed
{
    delete ui;
}

void MainWindow::changeWindowBev()  //functions to close the main window when corresponding windows are opened. currently unused
{
    if(addbeverage->isVisible())
    {
        addbeverage->hide();
        this->show();
    }
    else
    {
        this->hide();
        addbeverage->show();
    }
}

void MainWindow::on_pushButton_clicked()
{
    addbeverage->show();
}

void MainWindow::changeWindowTea()
{
    if(addtea->isVisible())
    {
        addtea->hide();
        this->show();
    }
    else
    {
        this->hide();
        addtea->show();
    }
}

void MainWindow::changeWindowCoffee()
{
    if(addcoffee->isVisible())
    {
        addcoffee->hide();
        this->show();
    }
    else
    {
        this->hide();
        addcoffee->show();
    }
}

void MainWindow::changeWindowOther()
{
    if(addother->isVisible())
    {
        addother->hide();
        this->show();
    }
    else
    {
        this->hide();
        addother->show();
    }
}

void MainWindow::changeWindowUp()
{
    if(lookup->isVisible())
    {
        lookup->hide();
        this->show();
    }
    else
    {
        this->hide();
        lookup->show();
    }
}

void MainWindow::on_pushButton_2_clicked()  //these open the corresponding windows
{
    addcoffee->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    addtea->show();
}


void MainWindow::on_pushButton_4_clicked()
{
    addother->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    lookup->show();
}

