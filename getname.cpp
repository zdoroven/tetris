#include "getname.h"
#include "ui_getname.h"
#include "functions.h"
#include <QFile>
#include <QString>
#include <QCoreApplication>
#include <QTextStream>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_backButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void Form::on_playButton_clicked()
{
    QString string;
    ui->playerName->text();
    this->close();
    tetris();
    this->show();
    QFile file("../tetris/leaderlist");
    if(file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream writeStream(&file);
        writeStream << string;
        file.close();
    }

    // Здесь нужна функция сортировки файла на наличие повторов имен и лучшие результаты,
    // т.к. появился новый игрок и новый результат
}
