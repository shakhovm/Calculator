#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    bool isFloat = false;
    bool isEnd = false;
    bool initialPosition = true;

    enum State {
        NOTHING,
        ADD_TRIGGER,
        SUB_TRIGGER,
        DIV_TRIGGER,
        POW_TRIGGER,
        MOD_TRIGGER,
        RT_TRIGGER,
        MUL_TRIGGER
    } state = NOTHING;


    double doubleDigit = 0.0;
    double secondDoubleDigit = 0.0;
private slots:
    void numberClick();

    void on_Button_Add_released();

    void on_Button_Point_released();

    void on_Button_Eq_released();

    void on_Button_CE_released();

    void on_Button_DEL_released();

    void on_Button_Sign_released();

    void on_Button_sin_released();

    void on_Button_Sub_released();

    void on_Button_Mul_released();

    void on_Button_DIV_released();

    void on_Button_MOD_released();

    void on_Button_POW_released();

    void on_Button_RT_released();

    void on_Button_cos_released();

    void on_Button_tg_released();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void doAction();
    void binaryOperations();
    void unaryOperations();
};

#endif // MAINWINDOW_H
