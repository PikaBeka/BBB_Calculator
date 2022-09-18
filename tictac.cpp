#include "tictac.h"
#include "ui_tictac.h"
#include "tictac_internal.cpp"
#include <string.h>
#include <iostream>

TicTac::TicTac(QWidget *parent) : QMainWindow(parent),
                                  ui(new Ui::TicTac)
{
    for (int i = 0; i < 9; i++)
    {
        this->grid[i] = -1;
    }

    this->firstCounter = this->secondCounter = 0;
    ui->setupUi(this);

    // Reset all values initially
    ui->PlayerName1->setText("");
    ui->PlayerName2->setText("");
    ui->PlayerScore1->setPlainText("0");
    ui->PlayerScore2->setPlainText("0");

    QPushButton *button;

    for(int i = 0; i < 9; i++){
        QString butName = "pushButton_"+QString::number(i);
        button = TicTac::findChild<QPushButton *>(butName);
        button->setText("");
    }

    // Start
    QString butName = "StartButton";
    QPushButton *StartButton = TicTac::findChild<QPushButton *>(butName);
    connect(StartButton, SIGNAL(released()), this, SLOT(Start()));

    // Press
    QPushButton *numButtons[9];

    for(int i = 0; i < 9; i++){
        QString butName = "pushButton_"+QString::number(i);
        numButtons[i] = TicTac::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(Press()));
    }

    // Reset
    butName = "ResetButton";
    QPushButton *ResetButton = TicTac::findChild<QPushButton *>(butName);
    connect(ResetButton, SIGNAL(released()), this, SLOT(Reset()));
}

TicTac::~TicTac()
{
    delete ui;
}

void TicTac::Start(){
    this->ui->PlayerName1->setReadOnly(true);
    this->ui->PlayerName2->setReadOnly(true);

    this->started = 1;
}

void TicTac::Press(){
    if(started == 0){
        return;
    }
    QPushButton* button = (QPushButton *) sender();

    if(button->text() != ""){
        return;
    }

    if(this->counter % 2 == 0){
        button->setText("X");
    }else{
        button->setText("O");
    }

    std::string butInd = button->objectName().toStdString();
    int isWin = this->PutItem(std::stoi(butInd.substr(butInd.size() - 1, 1)));
    if(isWin == 1){
        this->Reset();
        ui->PlayerScore1->setPlainText(QString::number(this->firstCounter));
        ui->PlayerScore2->setPlainText(QString::number(this->secondCounter));
    }
}

void TicTac::Reset(){
    if(started == 0){
        return;
    }

    QPushButton *button;

    for(int i = 0; i < 9; i++){
        QString butName = "pushButton_"+QString::number(i);
        button = TicTac::findChild<QPushButton *>(butName);
        button->setText("");
    }

    this->ResetCounter();
}
