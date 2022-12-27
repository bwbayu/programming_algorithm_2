#include "header.h"

void start(char pita[])
{
    idx = 0;
    length = 0;

    while (pita[idx] == ' ')
    {
        idx++;
    }

    while (pita[idx] != ' ' && pita[idx] != '.')
    {
        cc[length] = pita[idx];
        idx++;
        length++;
    }

    cc[length] = '\0';
}

void reset()
{
    length = 0;
    cc[length] = '\0';
}

void inc(char pita[])
{
    length = 0;
    while (pita[idx] == ' ')
    {
        idx++;
    }

    while (pita[idx] != ' ' && pita[idx] != '.')
    {
        cc[length] = pita[idx];
        idx++;
        length++;
    }

    cc[length] = '\0';
}

int eop(char pita[])
{
    if (pita[idx] == '.')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *getcc()
{
    return cc;
}

int getlength()
{
    return length;
}

int cekhuruf()
{
    int i = 0, n = 0;
    for (i = 0; i < length; i++)
    {
        if (cc[i] == 'a')
            n++;
    }

    return n;
}
