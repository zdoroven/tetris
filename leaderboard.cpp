#include "leaderboard.h"
#include "ui_leaderboard.h"
#include "app/functions.h"
#include <QFile>
#include <QString>

leaderboard::leaderboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leaderboard)
{
    ui->setupUi(this);
}

leaderboard::~leaderboard()
{
    delete ui;
}

void leaderboard::on_backButton_clicked()
{
    this->close();// Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}

void leaderboard::on_updateButton_clicked()
{
    QString string;
    QFile file("../tetris/leaderlist");
    file.open(QIODevice::ReadOnly);
    while((string = file.readLine()) != "")
    {
        ui->leaderList->append(string);
    }

    file.close();
}
