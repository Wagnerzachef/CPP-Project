#include "addbeverage.h"
#include "ui_addbeverage.h"

addBeverage::addBeverage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addBeverage)
{
    ui->setupUi(this);

}

addBeverage::~addBeverage()        //deletes the ui when the window is closed
{
    delete ui;
}

void addBeverage::on_pushButton_clicked()      //closes the window
{
    close();
}


void addBeverage::on_pushButton_2_clicked()       //puts the names in the tea table into the listWidget
{
    ui->beverageList->clear();
    DB_Connection.open();

    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    qry->exec("SELECT name FROM tea");

    int idName = qry->record().indexOf("name");

    while (qry->next())
    {
        QString name = qry->value(idName).toString();
        qDebug() << name;
        ui->beverageList->addItem(name);

    }

    QSqlDatabase::database().commit();
    DB_Connection.close();

}


void addBeverage::on_pushButton_3_clicked()              //puts the names in the coffee table into the listWidget
{
    ui->beverageList->clear();
    DB_Connection.open();

    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    qry->exec("SELECT name FROM coffee");

    int idName = qry->record().indexOf("name");

    while (qry->next())
    {
        QString name = qry->value(idName).toString();
        qDebug() << name;
        ui->beverageList->addItem(name);

    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void addBeverage::on_pushButton_4_clicked()                 //puts the names in the otherBeverage table into the listWidget
{
    ui->beverageList->clear();
    DB_Connection.open();

    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    qry->exec("SELECT name FROM otherBeverage");

    int idName = qry->record().indexOf("name");

    while (qry->next())
    {
        QString name = qry->value(idName).toString();
        //qDebug() << name;
        ui->beverageList->addItem(name);

    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void addBeverage::on_pushButton_5_clicked()                   //a button I made to show how to get the current item
{
    QString name = ui->beverageList->currentItem()->text();
    qDebug() << name;
}


void addBeverage::on_pushButton_6_clicked()              //inserts the data selected in the list widget, the entered fluid amount, and the date time of when it is inserted to the beverage_log table
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery qry;
    qry.prepare("INSERT INTO beverage_log ( beverageName, totalFluidOz, Date) VALUES (:name, :fluid, datetime('now', 'localtime'))");

    qry.bindValue(":name", ui->beverageList->currentItem()->text());
    qry.bindValue(":fluid", ui->lineEdit->text());


    if(qry.exec())
    {
        qDebug() << "success";
    }
    else
    {
        qDebug() << "addBeverage error:"
                 << qry.lastError();
    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}

