#ifndef TICTAC_H
#define TICTAC_H

#include <QMainWindow>

namespace Ui {
class TicTac;
}

class TicTac : public QMainWindow
{
    Q_OBJECT

public:
    explicit TicTac(QWidget *parent = 0);
    ~TicTac();

private:
    Ui::TicTac *ui;
};

#endif // TICTAC_H
