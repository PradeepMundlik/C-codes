/** Program written by Pradeep Mundlik (pradeepmundlik@gmail.com) **/

/************************************************************************************
This program adds two extemely large numbers (which long int can't store) using array. 
(e.g. 1111111111111111111111111111111111111111111111111111111111111111 + 2222222222222222222222222222222222222222222222222222 = 1111111111113333333333333333333333333333333333333333333333333333  )
*********************************************************************************/ 
#include <stdio.h>
#include <stdlib.h>

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
int mystrlen(char *str)
{
    int l = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        l++;
    }
    return l;
}
int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a > b ? b : a; }

void add(int *arr1, int *arr2, int l1, int l2)
{
    int k;
    int carry = 0;
    int *arr3 = (int *)calloc(l1 + 1, sizeof(int));
    for (int i = 0; i < l1; i++)
    {
        k = arr1[i] + arr2[i] + carry;
        arr3[l1 - i] = k % 10;
        if (k >= 10)
        {
            carry = 1;
        }
        if (k < 10)
        {
            carry = 0;
        }
    }

    if (carry == 1)
    {
        arr3[0] = 1;
        printarr(arr3, l1 + 1);
    }
    if (carry == 0)
    {
        for (int i = 0; i < l1; i++)
        {
            arr3[i] = arr3[i + 1];
        }
        printarr(arr3, l1);
    }
    free(arr3);
}
int main()
{
    int l = 1;
    while(l>0)
    {
        char *str1 = (char *)malloc(150 * sizeof(char));
        char *str2 = (char *)malloc(150 * sizeof(char));
        printf("Enter 1st number - ");
        scanf("%s", str1);
        getchar();
        printf("Enter 2nd number - ");
        scanf("%s", str2);
        getchar();
        
        str1 = (char *)realloc(str1, (mystrlen(str1) + 1) * sizeof(char));
        str2 = (char *)realloc(str2, (mystrlen(str2) + 1) * sizeof(char));

        int l1 = mystrlen(str1);
        int l2 = mystrlen(str2);

        int *arr1 = (int *)calloc(max(l1, l2), sizeof(int));
        int *arr2 = (int *)calloc(max(l1, l2), sizeof(int));

        for (int i = 0; i < mystrlen(str1); i++)
        {
            arr1[l1 - i - 1] = arr1[l1 - i - 1] * 10 + (str1[i] - 48);
        }
        for (int i = 0; i < mystrlen(str2); i++)
        {
            arr2[l2 - i - 1] = arr2[l2 - i - 1] * 10 + (str2[i] - 48);
        }

        free(str1);
        free(str2);
        int t = l1;
        l1 = max(l1, l2);
        l2 = min(t, l2);

        add(arr1, arr2, l1, l2);
        
    }
    return 0;
}