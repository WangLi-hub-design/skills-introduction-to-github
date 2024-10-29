#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int index_1, int index_2)
{
    int temp = a[index_1];
    a[index_1] = a[index_2];
    a[index_2] = temp;
}
int findPivot(int *a, int left, int right)
{
    while (left < right)
    {
        int pivotKey = a[left];

        while (left < right && pivotKey <= a[right])
        {
            right--;
        }
        swap(a, left, right);
        while (left < right && pivotKey >= a[left])
        {
            left++;
        }
        swap(a, left, right);
    }
    return left;
}

void QSort(int *a, int left, int right)
{
    if (left < right)
    {
        int pivot = findPivot(a, left, right);
        QSort(a, left, pivot - 1);
        QSort(a, pivot + 1, right);
    }
    
}

int main()
{
    int a[10] = {4,5,7,3,2,1,6,8,9,0};
    QSort(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
