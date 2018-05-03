#include "fillit.h"

void    sFill(t_global *figure, char *buff)
{
    int     ind;
    int     i;
    int     j;
    char    letter;

    i = 0;
    j = 0;
    letter = 'A';
    while (*buff)
    {
        ind = -1;
        while (ind <= 20)
        {
            if (buff[++ind] == '#' && j < 4)
            {
                figure->t[i].x[j] = ind % 5;
                figure->t[i].y[j] = ind / 5;
                j++;
            }
        }
        figure->t[i].field = letter++;
        i++;
        j = 0;
        buff += 21;
    }
    print1(figure, buff);
}

void    sShuffle(t_global *figure, char *buff)
{
    int     i;
    int     col;

    i = 0;
    col = tCount(buff);
    while (i < col)
    {
        sShuffleX(figure, i);
        sShuffleY(figure, i);
        i++;
    }
}

void    sShuffleX(t_global *figure, int i)
{
    int     a;
    int     b;
    int     c;
    int     d;

    a = figure->t[i].x[0];
    b = figure->t[i].x[1];
    c = figure->t[i].x[2];
    d = figure->t[i].x[3];
    while (a != 0)
    {
        a -= 1;
        b -= 1;
        c -= 1;
        d -= 1;
    }
    figure->t[i].x[0] = a;
    figure->t[i].x[1] = b;
    figure->t[i].x[2] = c;
    figure->t[i].x[3] = d;
}

void    sShuffleY(t_global *figure, int i)
{
    int     a;
    int     b;
    int     c;
    int     d;

    a = figure->t[i].y[0];
    b = figure->t[i].y[1];
    c = figure->t[i].y[2];
    d = figure->t[i].y[3];
    while (a != 0 )
    {
        a -= 1;
        b -= 1;
        c -= 1;
        d -= 1;
    }
    figure->t[i].y[0] = a;
    figure->t[i].y[1] = b;
    figure->t[i].y[2] = c;
    figure->t[i].y[3] = d;
}
