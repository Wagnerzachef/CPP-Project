#include "lookup.h"
#include "ui_lookup.h"

lookUp::lookUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::lookUp)
{
    ui->setupUi(this);
}

lookUp::~lookUp()        //deletes the ui when the window is closed
{
    delete ui;
}

void lookUp::on_pushButton_4_clicked()                      //button looks up data from past 24 hours
{
    QSqlQueryModel *model = new QSqlQueryModel();
    //QSqlQueryModel *model2 = new QSqlQueryModel();
    DB_Connection.open();


    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    //QSqlQuery* qry2 = new QSqlQuery(DB_Connection);
    qry->exec("SELECT beverageName, totalFluidOz, Date FROM beverage_log WHERE date BETWEEN datetime('now', '-1 days') AND datetime('now', 'localtime')");
    //int idName = qry->record().indexOf("beverageName");

   // while (qry->next())
    //{
       // QString name = qry->value(idName).toString();
       // qDebug() << name;
       // ui->lineEdit_2->setText(name);
       // qry2->prepare("SELECT caffeine_mg FROM tea WHERE name LIKE '(:name)'");
       // qry2->bindValue(":name", ui->lineEdit_2->text());
       // qry2->exec();

        //model2->setQuery(*qry2);

      //  ui->tableView_2->setModel(model2);
    //}
    model->setQuery(*qry);
    ui->tableView->setModel(model);                                 //sets the table view to the model
    ui->tableView->setColumnWidth(2, 150);                          //sets the width of the column


    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void lookUp::on_pushButton_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    DB_Connection.open();

    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    qry->exec("SELECT beverageName, totalFluidOz, Date FROM beverage_log WHERE date BETWEEN datetime('now', '-7 days') AND datetime('now', 'localtime')");

    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(2, 150);

    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void lookUp::on_pushButton_2_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    DB_Connection.open();

    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    qry->prepare("SELECT beverageName, totalFluidOz, Date FROM beverage_log WHERE beverageName = :name");

    qry->bindValue(":name", ui->lineEdit->text());

    qry->exec();

    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(2, 150);

    QSqlDatabase::database().commit();
    DB_Connection.close();
}


void lookUp::on_pushButton_3_clicked()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    DB_Connection.open();

    QSqlQuery* qry = new QSqlQuery(DB_Connection);
    qry->exec("SELECT beverageName, totalFluidOz, Date FROM beverage_log WHERE date BETWEEN datetime('now', '-30 days') AND datetime('now', 'localtime')");

    model->setQuery(*qry);
    ui->tableView->setModel(model);
    ui->tableView->setColumnWidth(2, 150);

    QSqlDatabase::database().commit();
    DB_Connection.close();
}

