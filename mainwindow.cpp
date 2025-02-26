#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->username->setPlaceholderText("Введите имя пользователя");
    ui->password->setPlaceholderText("Введите пароль");
    ui->email->setPlaceholderText("Введите адрес почты");
    ui->phonenumber->setPlaceholderText("Введите номер телефона");
    ui->loginname->setPlaceholderText("Введите имя пользователя");
    ui->loginpassword->setPlaceholderText("Введите пароль");

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("./regDB.db");

    if (database.open()) {
        query = new QSqlQuery (database);
        query->exec("CREATE TABLE regtable(Username TEXT, Password TEXT, Email TEXT, Phone TEXT);");

        regmodel = new QSqlTableModel (this, database);
        regmodel->setTable("regtable");
        regmodel->select();

    } else {
        QMessageBox::warning(this, "Ошибка!", "База данных не подключена!");
    }
}

MainWindow::~MainWindow()
{
    database.close();
    delete ui;
}


void MainWindow::on_pushButton_clicked() // кнопка регистрации
{
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString email = ui->email->text();
    QString phonenumber = ui->phonenumber->text();

    if (ui->username->text().isEmpty() or ui->password->text().isEmpty() or ui->email->text().isEmpty() or ui->phonenumber->text().isEmpty()){

        QMessageBox::warning(this, "Ошибка!", "Заполните все поля формы регистрации!");

    } else {
        query->prepare("INSERT INTO regtable(Username, Password, Email, Phone)"
                       "VALUES (:username, :password, :email, :phonenumber)");

        query->bindValue(":username", username);
        query->bindValue(":password", password);
        query->bindValue(":email", email);
        query->bindValue(":phonenumber", phonenumber);

        if (query->exec()) {
            QMessageBox::information(this, "Выполнено!", "Данные успешно добавлены!");
        } else {
            QMessageBox::warning(this, "Ошибка!", "Данные не добавлены!");
        }
    }

    ui->username->clear();
    ui->password->clear();
    ui->email->clear();
    ui->phonenumber->clear();
}


void MainWindow::on_pushButton_2_clicked()//кнопка входа
{
    QString username = ui->loginname->text();
    QString password = ui->loginpassword->text();

    if (ui->loginname->text().isEmpty() or ui->loginpassword->text().isEmpty())
    {

        QMessageBox::warning(this, "Ошибка!", "Заполните все поля формы входа!");
    }
    else
    {
        query->prepare(QString("SELECT * FROM regtable WHERE username =:username AND password =:password"));

        query->bindValue(":username", username);
        query->bindValue(":password", password);

        if (query->exec()) { //запрос к БД

            while (query->next())// перемещение указателя к следующей записи в БД
            {
                QString namefromDB = query->value("Username").toString();
                QString passwordfromDB = query->value("Password").toString();

                if (namefromDB == username && passwordfromDB == password)
                {
                    regbase dbView;
                    dbView.setModal(true);
                    dbView.exec();

                } else {

                    QMessageBox::warning(this, "Ошибка!", "Доступ запрещён!");

                }
            }

        } else {

            QMessageBox::warning(this, "Ошибка!", "Не удалось выполнить запрос!");

        }
    }

    ui->loginname->clear();
    ui->loginpassword->clear();
}

