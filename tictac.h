#ifndef TICTAC_H
#define TICTAC_H

#include <QMainWindow>

namespace Ui
{
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
    int counter;
    int firstCounter, secondCounter;
    std::string firstName, secondName;
    int8_t grid[9];
    int IsWin(int);             // done
    int PutItem(int);           // done
    void ResetCounter();        // done
    bool compareGrid(int, int); // done
    static int const winGrids[8][9] = {
        {1, 0, 0, 0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 1},
        {1, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 1, 1},
    };

private slots:
    void
    Start();
    void Reset();
    void Press(); // counter increment -> counter %2 == 0 -> Change text to X/O (PutItem())
};

#endif // TICTAC_H
