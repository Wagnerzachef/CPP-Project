#ifndef ADDTEA_H
#define ADDTEA_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class addTea;
}

class addTea : public QDialog
{
    Q_OBJECT

public:
    explicit addTea(QWidget *parent = nullptr);
    ~addTea();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::addTea *ui;
    QSqlDatabase DB_Connection;
    int teaNumber;
};

#endif // ADDTEA_H
