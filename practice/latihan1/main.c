#include "header.h"

int main()
{
    char pita[50];
    int n = 0;
    scanf("%49[^\n]s", pita);

    start(pita);
    while (eop() == 0)
    {
        if (getcc() != ' ')
        {
            char temp = getcc();
            inc(pita);
            if (eop() == 0)
            {
                if (getcc() == ' ')
                {
                    char temp2 = getcc();
                    inc(pita);
                    if (eop() == 0)
                    {
                        if (getcc() != ' ' && temp2 == ' ' && temp != ' ')
                        {
                            n++;
                        }
                        else
                        {
                            adv(pita);
                        }
                    }
                }
            }
        }
        else
        {
            adv(pita);
        }
    }

    printf("%d\n", n);
    return 0;
}