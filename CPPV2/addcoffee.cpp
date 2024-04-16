#include "addcoffee.h"
#include "ui_addcoffee.h"

addCoffee::addCoffee(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addCoffee)
{
    ui->setupUi(this);

}

addCoffee::~addCoffee()        //deletes the ui when the window is closed
{
    delete ui;
}

void addCoffee::on_pushButton_clicked()         //inserts the enterd data into the coffee table
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery qry;
    qry.prepare("INSERT INTO coffee ( name, caffeine_mg, liquid_amount) VALUES (:name, :caffiene_mg, :liquid_amount)");

    qry.bindValue(":name", ui->lineEdit->text());
    qry.bindValue(":caffiene_mg", ui->lineEdit_2->text());
    qry.bindValue(":liquid_amount", ui->lineEdit_3->text());


    if(qry.exec())
    {
        qDebug() << "success";
    }
    else
    {
        qDebug() << "addCoffee error:"
                 << qry.lastError();
    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void addCoffee::on_pushButton_2_clicked()      //closes the window
{
    close();
}

