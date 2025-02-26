#ifndef REGBASE_H
#define REGBASE_H

#include <QDialog>
#include "mainwindow.h"
#include <QtSql>
#include <QSqlDatabase>


namespace Ui {
class regbase;
}

class regbase : public QDialog
{
    Q_OBJECT

public:
    explicit regbase(QWidget *parent = nullptr);
    ~regbase();

private:
    Ui::regbase *ui;
    QSqlDatabase database;
    QSqlTableModel *regmodel;


};
#endif // REGBASE_H
