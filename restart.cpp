#include "restart.h"
#include "ui_restart.h"
#include "app/functions.h"
#include <QProcess>
#include "getname.h"

Restart::Restart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Restart)
{
    ui->setupUi(this);
    tWindow = new Form();
    connect(tWindow, &Form::mainWindow, this, &Restart::show);
   }

Restart::~Restart()
{
    delete ui;
}

void Restart::on_restartButton_clicked()
{
    this->close();
    tetris();
}

void Restart::on_backButton_clicked()
{
    this->close();      // Закрываем окно
    emit firstWindow();
}
