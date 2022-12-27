#include "header.h"

int main()
{
    char pita[100], kata[50][100];
    // int n = 0;
    scanf("%99[^\n]s", pita);

    start(pita);
    if (cekhuruf() > 1)

        while (eop(pita) == 0)
        {
            inc(pita);
            if (cekhuruf() > 1)
        }

    // printf("%d\n", n);

    return 0;
}