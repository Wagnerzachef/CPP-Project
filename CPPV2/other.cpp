#include "other.h"
#include "ui_other.h"

other::other(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::other)
{
    ui->setupUi(this);
}

other::~other()        //deletes the ui when the window is closed
{
    delete ui;
}

void other::on_pushButton_2_clicked()            //closes the window
{
    close();
}


void other::on_pushButton_clicked()             //adds entered data into the otherBeverage table
{
    DB_Connection.open();
    QSqlDatabase::database().transaction();

    QSqlQuery qry;
    qry.prepare("INSERT INTO otherBeverage ( name, caffeine_mg, liquid_amount) VALUES (:name, :caffiene_mg, :liquid_amount)");

    qry.bindValue(":name", ui->lineEdit->text());
    qry.bindValue(":caffiene_mg", ui->lineEdit_2->text());
    qry.bindValue(":liquid_amount", ui->lineEdit_3->text());


    if(qry.exec())
    {
        qDebug() << "success";
    }
    else
    {
        qDebug() << "other error:"
                 << qry.lastError();
    }

    QSqlDatabase::database().commit();
    DB_Connection.close();
}

