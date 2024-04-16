#include "addtea.h"
#include "ui_addtea.h"

addTea::addTea(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addTea)
{
    ui->setupUi(this);

    QSqlDatabase DB_Connection = QSqlDatabase::addDatabase("QSQLITE");
    DB_Connection.setDatabaseName("C:/sqlite/CPPproject.v1.db");

}

addTea::~addTea()        //deletes the ui when the window is closed
{
    delete ui;
}

void addTea::on_pushButton_clicked()          //inserts data into the tea table
{


    DB_Connection.open();                           //this opens the connection to the database
    QSqlDatabase::database().transaction();

    QSqlQuery qry;
    qry.prepare("INSERT INTO tea ( name, caffeine_mg, liquid_amount) VALUES (:name, :caffiene_mg, :liquid_amount)");

    qry.bindValue(":name", ui->lineEdit->text());
    qry.bindValue(":caffiene_mg", ui->lineEdit_2->text());
    qry.bindValue(":liquid_amount", ui->lineEdit_3->text());


    if(qry.exec())
    {
        qDebug() << "success";
    }
    else
    {
        qDebug() << "addTea error:"
                 << qry.lastError();
    }

    QSqlDatabase::database().commit();
    DB_Connection.close();                      //this closes the database connection
}


void addTea::on_pushButton_2_clicked()            //closes the window
{
    close();
}

