#ifndef RESTART_H
#define RESTART_H

#include <QWidget>

namespace Ui {
class Restart;
}

class Restart : public QWidget
{
    Q_OBJECT

public:
    explicit Restart(QWidget *parent = 0);
    ~Restart();
signals:
    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    // Слот-обработчик нажатия кнопки
    void on_backButton_clicked();


    void on_restartButton_clicked();

private:
    Ui::Restart *ui;
};

#endif // RESTART_H
