#include "tictac.h"
#include "ui_tictac.h"

TicTac::TicTac(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TicTac)
{
    ui->setupUi(this);
}

TicTac::~TicTac()
{
    delete ui;
}
