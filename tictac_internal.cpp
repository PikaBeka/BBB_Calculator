#include "tictac.h"

int TicTac::PutItem(int n)
{
    this.counter++;
    this->grid[n] = this.counter % 2;
    return this->IsWin(this.counter % 2);
}

int TicTac::IsWin(int mask)
{
    for (int i = 0; i < 8; i++)
    {
        if (this->compareGrid(mask, i))
        {
            mask % 2 == 1 ? this->firstCounter++ : this->secondCounter++;
            return 1;
        }
        return 0;
    }
}

bool TicTac::compareGrid(int mask, int idx)
{
    int8_t compare[9];
    for (int i = 0; i < 9; i++)
    {
        compare[i] = this->grid[i] == mask ? 1 : 0;
    }

    for (int i = 0; i < 9; i++)
    {
        if (compare[i] != this->winGrids[idx][i])
            return false;
    }

    return true;
}

void TicTac::ResetCounter()
{
    this->counter = 0;
}