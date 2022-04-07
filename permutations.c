/***********    Program by Pradeep Mundlik (pradeepmundlik@gmail.com)  *************/

/**********************************************************************
 This function takes length of string and string as input and prints all possible permutations of string.
 String can contain repeatations of characters. 
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
    char t;
    t = *a;
    *a = *b;
    *b = t;
}

void printpermutations(int n, char *str, int i, char **list, int *z)
{

    if (i == n - 1)
    {

        // printf("%d %s\n", *z, str);
        strcpy(*(list + *z), str);
        *z += 1;
    }
    else
        for (int j = i; j < n; j++)
        {
            if (j == i)
            {
                swap(str + i, str + j);
                printpermutations(n, str, i + 1, list, z);
                swap(str + i, str + j);
            }
            // when i != j
            else if (str[i] != str[j])
            {
                swap(str + i, str + j);
                printpermutations(n, str, i + 1, list, z);
                swap(str + i, str + j);
            }
        }
}
void remove_same_elements(char **list, int *z)
{
    for (int i = 0; i < *z; i++)
    {
        if (strcmp(list[i], "#") != 0)
        {
            for (int j = i + 1; j < *z; j++)
            {
                if (strcmp(list[i], list[j]) == 0)
                {
                    strcpy(list[j], "#");
                }
            }
        }
    }
}
int main()
{
    int n = 0;
    int z = 0;
    printf("Enter length of string - ");
    scanf("%d", &n);
    printf("Enter string - ");
    char *str = (char *)calloc(n + 1, sizeof(char));
    char **list = (char **)calloc(362880, sizeof(char *));
    for (int i = 0; i < 362880; i++)
    {
        list[i] = calloc(n + 1, sizeof(char));
    }

    getchar();
    gets(str);

    printpermutations(n, str, 0, list, &z);

    list[z] = "\0";
    list = (char **)realloc(list, (z + 1) * sizeof(char));

    remove_same_elements(list, &z);
    int j = 1;
    for (int i = 0; i < z; i++)
    {
        if (strcmp(list[i],"#") != 0)
        {
            printf("%d %s\n",j, list[i]);
            j++;
        }
        free(list[i]);
    }
    free(list);
    free(str);

    return 0;
}
