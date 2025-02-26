/********************************************************************************
** Form generated from reading UI file 'regbase.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGBASE_H
#define UI_REGBASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_regbase
{
public:
    QVBoxLayout *verticalLayout;
    QTableView *regView;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *regbase)
    {
        if (regbase->objectName().isEmpty())
            regbase->setObjectName(QString::fromUtf8("regbase"));
        regbase->resize(646, 457);
        regbase->setStyleSheet(QString::fromUtf8("#regbase {\n"
"	background-color: rgb(0, 0, 255);\n"
";\n"
"}"));
        verticalLayout = new QVBoxLayout(regbase);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        regView = new QTableView(regbase);
        regView->setObjectName(QString::fromUtf8("regView"));

        verticalLayout->addWidget(regView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(regbase);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(regbase);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(regbase);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(regbase);

        QMetaObject::connectSlotsByName(regbase);
    } // setupUi

    void retranslateUi(QDialog *regbase)
    {
        regbase->setWindowTitle(QCoreApplication::translate("regbase", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("regbase", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("regbase", "2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("regbase", "3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class regbase: public Ui_regbase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGBASE_H
