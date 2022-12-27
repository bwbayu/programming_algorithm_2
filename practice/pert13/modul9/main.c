#include "header.h"

int main()
{
    char pita[50];
    int n = 0;
    char temp;
    scanf("%49[^\n]s", &pita);

    START(pita);
    printf("%c", GETCC());
    while (EOP() == 0)
    {
        temp = GETCC();
        INC(pita);
        if (EOP() == 0)
        {
            if (temp == 's' && GETCC() == 'e')
            {
                n++;
            }
            printf("%c", GETCC());
        }
    }
    printf("\nJumlah suku kata : %d\n", n);
    return 0;
}