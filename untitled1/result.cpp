#include "result.h"
#include "ui_result.h"
#include "app/functions.h"
#include "getname.h"

resultat::resultat(QWidget *parent) :
    QWidget(parent),
    ui(new resultat)
{
    ui->setupUi(this);

    //form = new Form();
    //connect(form, &Form::nextWindow, this, &result::show);

}

void resultat::on_restartButton_clicked()
{
    tetris();
}

void resultat::on_menuButton_clicked()
{
    this->close();// Закрываем окно
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
}
