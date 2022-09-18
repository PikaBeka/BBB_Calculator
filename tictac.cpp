#include "tictac.h"
#include "ui_tictac.h"

TicTac::TicTac(QWidget *parent) : QMainWindow(parent),
                                  ui(new Ui::TicTac)
{
    for (int i = 0; i < 9; i++)
    {
        this->grid[i] = -1;
    }

    this->firstCounter = this->secondCounter = 0;
    ui->setupUi(this);
}

TicTac::~TicTac()
{
    delete ui;
}
