#ifndef LOOKUP_H
#define LOOKUP_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class lookUp;
}

class lookUp : public QDialog
{
    Q_OBJECT

public:
    explicit lookUp(QWidget *parent = nullptr);
    ~lookUp();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::lookUp *ui;
    int safeCaffiene = 400;
    QSqlDatabase DB_Connection;
    int currentCaffeine;
};

#endif // LOOKUP_H
