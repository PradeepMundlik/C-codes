                                                    /***** ROCK PAPER SCISSORS GAME *****/
                                                        /* By Pradeep Mundlik
                                                      pradeepmundlik@gmail.com */

                                                    /*******************************
                                                     rock vs paper ===> paper(1)
                                                     rock vs scissors ===> rock(0)
                                                     paper vs scissors ===> scissors(2)
                                                    ********************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int randomnumber()
{
    srand(time(NULL));
    return rand() % 3;
}
char computermove(int a)
{
    if (a == 0)
    {
        return 'r';
    }
    else if (a == 1)
    {
        return 'p';
    }
    else if (a == 2)
    {
        return 's';
    }
}
int game(char a, char b)
{
    if ((a == 'r' && b == 'p') || (a == 'p' && b == 's') || (a == 's' && b == 'r'))
    {
        return 2;
    }
    else if (a == b)
    {
        return 0;
    }
    else
        return 1;
}
int main()
{
    int score_of_p = 0; //--> stores score of player .
    int score_of_c = 0; //--> stores score of computer.
    char p;
    char c;
    int i = 0;
    printf("\nEnter r for rock\n      s for scissor\n      p for paper\n\n");
    while (i < 5)
    {
        printf("ROUND %d\n\n", i + 1);
        printf("Make your move-\n");
        scanf("%c", &p);
        printf("computer's move-\n%c", computermove(randomnumber()));

        c = computermove(randomnumber());

        if (game(p, c) == 1)
        {
            score_of_p++;
        }
        else if (game(p, c) == 2)
        {
            score_of_c++;
        }

        i++;
        getchar();
        printf("\n\nScores at end of Round-%d are:\nPlayer = %d\nComputer = %d\n\n", i , score_of_p, score_of_c);
    }
    label:
    if (score_of_c == score_of_p)
    {   
        printf("ROUND %d[extra round]\n\n", i + 1);
        printf("Make your move-\n");
        scanf("%c", &p);
        printf("computer's move-\n%c", computermove(randomnumber()));

        c = computermove(randomnumber());

        if (game(p, c) == 1)
        {
            score_of_p++;
        }
        else if (game(p, c) == 2)
        {
            score_of_c++;
        }

        i++;
        getchar();
        printf("\nScores at end of Round-%d are:\nPlayer = %d\nComputer = %d\n\n", i , score_of_p, score_of_c);
        goto label;
    }
    
    if (score_of_p > score_of_c)
    {
        printf("\n\nCongratulations!! You Win....!!\n");
    }
    else
        printf("\n\nOops!! You Loose....\n");
    return 0;
}