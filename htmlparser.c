#include <stdio.h>
#include <string.h>
void parser(char *str)
{
    int a = 0, b = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == '<')
        {
            a = 0;
            continue;
        }
        if (str[i] == '>')
        {
            a = 1;
            continue;
        }
        if (a == 1)
        {
            str[b] = str[i];
            b++;
        }
    }
    str[b] = '\0';
    while (str[0]==' ')
    {
        for (int i = 0; i < b ; i++)
        {
            str[i]=str[i+1];
        }
    }
    while (str[strlen(str)-1]==' ')
    {
        str[strlen(str)-1]='\0';
    }
    
}
int main()
{
    char str[] = "<hhfgf>      This is    Heading      <ghgdfdfgf   hgh>";
    parser(str);
    printf("{%s}", str);
    return 0;
}