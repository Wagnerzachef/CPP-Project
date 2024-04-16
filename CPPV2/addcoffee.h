#ifndef ADDCOFFEE_H
#define ADDCOFFEE_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class addCoffee;
}

class addCoffee : public QDialog
{
    Q_OBJECT

public:
    explicit addCoffee(QWidget *parent = nullptr);
    ~addCoffee();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addCoffee *ui;
    QSqlDatabase DB_Connection;
};

#endif // ADDCOFFEE_H
