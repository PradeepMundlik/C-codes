                            /**************************************************************************************
                             This program computes all possible permutations of numbers from 1 to n. (n is user input number)
                            eg. if input n = 3 then you will get 6 permutations - 123, 132, 213, 231, 312, 321.
                            ****************************************************************************************/

                                                    /***************************
                                                     Program by Pradeep Mundlik
                                                    email - pradeepmundlik@gmail.com 
                                                    ****************************/

#include <stdio.h>
#include <stdlib.h>
void printArr(int* arr , int n)
{  for (int i = 0; i < n; i++) { printf("%d ", arr[i]) ; }  }

void printpermutation(int* set, int* prefix, int n, int current)
{
    if (current == n)
    {
        printArr(prefix , n);
        printf("\n");
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (set[i] != -1)
            {   int t = set[i];
                prefix[current] = set[i];
                set[i] = -1 ;

                printpermutation(set, prefix, n, current+1);
                set[i] = t ;
            }
        }
        
    }
}
int main()
{
    int n;
    printf("Enter any natural number to see all possible permutations of numbers from 1 to n:\n");
    scanf("%d", &n);
    int *set;
    int *prefix;

    set = (int *)calloc(n, sizeof(int));
    prefix = (int *)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) { set[i] = i + 1 ; }
    int current = 0 ;
    printpermutation(set, prefix, n, current);
    free(set);
    free(prefix);
   
     
    return 0;
}