#include <stdio.h>
#include "mesinkarakter.h"

int main()
{
    char pita[50];
    int n = 0;
    char temp, temp2;
    scanf("%49[^\n]s", &pita);

    START(pita);
    while (EOP() == 0)
    {
        temp = GETCC();
        INC(pita);
        if (EOP() == 0)
        {
            temp2 = GETCC();
            INC(pita);
            if (EOP() == 0)
            {
                if (temp == 'k' && temp2 == 'a' && GETCC() == 'k')
                {
                    n++;
                }
            }
            DEC(pita);
        }
    }
    printf("banyaknya huruf kak = %d", n);
    return 0;
}