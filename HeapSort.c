#include <stdio.h>
#include <stdlib.h>

void Swap(int *a, int index_1, int index_2)
{
    int temp = a[index_1];
    a[index_1] = a[index_2];
    a[index_2] = temp;
}

void HeadAdjust(int *a, int root, int len)
{
    int i, temp = a[root];
    for (i = root * 2; i < len; i++)
    {
        if (a[i] < a[i + 1])
        {
            ++i;
        }
        if (temp < a[i])
        {
            a[root] = a[i];
            root = i;
        }
    }
    a[root] = temp;
}
void HeapSort(int *a, int len)
{
    int i;
    for (i = len / 2 - 1; i >= 0; i--)
    {
        HeadAdjust(a, i, len - 1);
    }
    for (i = len - 1; i >= 1; i--)
    {
        Swap(a, 0, i); /*将堆顶（最大值）和末尾要素交换，此时确定一个最大值在末尾*/
        HeadAdjust(a, 0, i - 1);/*再比较剩下的元素，将新的最大值移至堆顶*/
    }
    
}

int main()
{
    int a[10] = {5,6,4,3,2,1,8,9,7,0};
    HeapSort(a, 10);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    return 0;
}
