#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *numButtons[10];
    for (int i = 0; i < 10; ++i) {
        numButtons[i] = MainWindow::findChild<QPushButton*>("Button_" + QString::number(i));
        connect(numButtons[i], SIGNAL(released()), this, SLOT(numberClick()));
    }
    ui->label->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::doAction()
{

    secondDoubleDigit = ui->label->text().toDouble();
    switch (state) {

        case NOTHING:
            doubleDigit = secondDoubleDigit;
            break;

        case ADD_TRIGGER:
            doubleDigit += secondDoubleDigit;
            break;

        case SUB_TRIGGER:
            doubleDigit -= secondDoubleDigit;
            break;

        case MUL_TRIGGER:
            doubleDigit *= secondDoubleDigit;
            break;

        case DIV_TRIGGER:
            doubleDigit /= secondDoubleDigit;
            break;

        case POW_TRIGGER:
            doubleDigit = std::pow(doubleDigit, secondDoubleDigit);
            break;

        case MOD_TRIGGER:
            doubleDigit = std::fmod(doubleDigit, secondDoubleDigit);
            break;

        case RT_TRIGGER:
            doubleDigit = std::pow(doubleDigit, 1/secondDoubleDigit);
            break;

    }
    ui->label->setText(QString::number(doubleDigit));
}

void MainWindow::binaryOperations()
{
    QString currentText = ui->label->text();

    if(state == NOTHING)
    {
        doubleDigit = currentText.toDouble();
    }

    doAction();
    initialPosition = true;

}

void MainWindow::unaryOperations()
{
    ui->label->setText(QString::number(secondDoubleDigit));
    doAction();
    state = NOTHING;
    initialPosition = true;
}


void MainWindow::numberClick()
{
    QString text = static_cast<QPushButton*>(sender())->text();
    if (ui->label->text() == "0" && text == "0") {
        return;
    }
    if (initialPosition)
    {
        ui->label->setText("");
        initialPosition = false;
    }


    ui->label->setText(ui->label->text() + text);
}

void MainWindow::on_Button_Point_released()
{
    if(ui->label->text().contains("."))
        return;
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::on_Button_Eq_released()
{
    doAction();
    state = NOTHING;
    initialPosition = true;
}

void MainWindow::on_Button_CE_released()
{
    secondDoubleDigit = 0.0;
    doubleDigit = 0.0;
    ui->label->setText("0");
    initialPosition = true;
    state = NOTHING;
}

void MainWindow::on_Button_DEL_released()
{
    QString text = ui->label->text();
    if (text.size() == 1) {
        ui->label->setText("0");
        initialPosition = true;
        return;
    }
    ui->label->setText(text.left(text.size() - 1));
}

void MainWindow::on_Button_Sign_released()
{
    QString currentText = ui->label->text();
    if (currentText.startsWith("-"))
        ui->label->setText(currentText.remove("-"));
    else
        ui->label->setText("-" + currentText);
}


void MainWindow::on_Button_Add_released()
{
    binaryOperations();
    state = ADD_TRIGGER;
}

void MainWindow::on_Button_Sub_released()
{
    binaryOperations();
    state = SUB_TRIGGER;
}

void MainWindow::on_Button_Mul_released()
{
    binaryOperations();
    state = MUL_TRIGGER;
}

void MainWindow::on_Button_DIV_released()
{
    binaryOperations();
    state = DIV_TRIGGER;
}

void MainWindow::on_Button_MOD_released()
{
    binaryOperations();
    state = MOD_TRIGGER;
}

void MainWindow::on_Button_POW_released()
{
    binaryOperations();
    state = POW_TRIGGER;
}

void MainWindow::on_Button_RT_released()
{
    binaryOperations();
    state = RT_TRIGGER;
}

void MainWindow::on_Button_sin_released()
{
    secondDoubleDigit = std::sin(ui->label->text().toDouble());
    unaryOperations();
}



void MainWindow::on_Button_cos_released()
{
    secondDoubleDigit = std::cos(ui->label->text().toDouble());
    unaryOperations();
}

void MainWindow::on_Button_tg_released()
{
    secondDoubleDigit = std::tan(ui->label->text().toDouble());
    unaryOperations();
}
