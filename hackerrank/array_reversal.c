#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) 
        scanf("%d", &arr[i]);
    int k = 0;
    int tmp;
    int nb = num - 1;
    while (k < nb)
    {
        tmp = arr[k];
        arr[k] = arr[nb];
        arr[nb] = tmp; 
        k++;
        nb--;
    }
    for(i = 0; i < num; i++)
        printf("%d ", arr[i]);
    return 0;
}