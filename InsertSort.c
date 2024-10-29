#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[10] = {4,5,7,3,2,1,6,8,9,0};
    int i, j, temp;
    for (i = 0; i < 10; i++)
    {
        if (a[i] > a[i + 1] && i + 1 < 10)
        {
            int temp = a[i + 1];
            for (j = i; a[j] > temp && j >= 0; j--)
            {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
    

    for (i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");

    return 0;
}
