#ifndef RESULT_H
#define RESULT_H

#include <QWidget>
#include <getname.h>

class resultat : public QWidget
{
    Q_OBJECT

public:
    explicit resultat(QWidget *parent = 0);
    ~resultat();

signals:
    void firstWindow();  // Сигнал для первого окна на открытие
    void nextWindow();
private slots:
    // Слот-обработчик нажатия кнопки
    void on_restartButton_clicked();
    void on_menuButton_clicked();

private:
    //Ui::resultat *ui;
    //Form *form;
};

#endif // RESULT_H
