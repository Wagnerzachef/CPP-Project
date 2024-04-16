#ifndef OTHER_H
#define OTHER_H

#include <QDialog>
#include <QtSql>

namespace Ui {
class other;
}

class other : public QDialog
{
    Q_OBJECT

public:
    explicit other(QWidget *parent = nullptr);
    ~other();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::other *ui;
    QSqlDatabase DB_Connection;
};

#endif // OTHER_H
