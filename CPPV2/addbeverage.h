#ifndef ADDBEVERAGE_H
#define ADDBEVERAGE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class addBeverage;
}

class addBeverage : public QDialog
{
    Q_OBJECT

public:
    explicit addBeverage(QWidget *parent = nullptr);
    ~addBeverage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::addBeverage *ui;
    QSqlDatabase DB_Connection;
};

#endif // ADDBEVERAGE_H
