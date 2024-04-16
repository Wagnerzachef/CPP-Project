#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <addbeverage.h>
#include <QMainWindow>
#include <addtea.h>
#include <addcoffee.h>
#include <other.h>
#include <lookup.h>

#include <QtSql>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void changeWindowTea();

    void changeWindowCoffee();

    void changeWindowOther();

    void changeWindowBev();

    void changeWindowUp();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase DB_Connection;
    int teaNumber;
    addTea *addtea;
    addBeverage *addbeverage;
    addCoffee *addcoffee;
    other *addother;
    lookUp *lookup;
};
#endif // MAINWINDOW_H
