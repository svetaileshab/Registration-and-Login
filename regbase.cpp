#include "regbase.h"
#include "ui_regbase.h"

regbase::regbase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::regbase)
{
    ui->setupUi(this);

    regmodel = new QSqlTableModel();
    regmodel->setTable("regtable");
    regmodel->select();

//    regmodel->setHeaderData(0, Qt::Horizontal, tr("ID")); // если надо изменить название столбца

    ui->regView->setModel(regmodel);
}

regbase::~regbase()
{
    delete ui;
}
