#include "header.h"

void start(char pita[])
{
    idx = 0;
    cc = pita[idx];
}

void inc(char pita[])
{
    idx++;
    cc = pita[idx];
}

void dec(char pita[])
{
    idx--;
    cc = pita[idx];
}

int eop()
{
    if (cc == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void adv(char pita[])
{
    idx++;
    cc = pita[idx];
    while (cc == ' ' && eop() == 0)
    {
        idx++;
        cc = pita[idx];
    }
}

char getcc()
{
    return cc;
}