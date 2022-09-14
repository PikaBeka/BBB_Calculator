#include "calculator.h"
#include "ui_calculator.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addrigger = false;
bool subTrigger = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];

    for(int i = 0; i < 10; i++){
        QString butName = "Button"+QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::NumPressed(){
    QPushButton *button = (QPushButton *) sender();
    QString butval = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->Display->setText(butval);
    }else{
        QString newVal = displayVal + butval;
        double dblNewVal = newVal.toDouble()
    }
}
