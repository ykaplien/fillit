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
            if (buff[++ind] == '#')
            {
                figure->ter[i].x[j] = ind % 5;
                figure->ter[i].y[j] = ind / 5;
                j++;
            }
        }
        figure->ter[i].field = letter++;
        i++;
        j = 0;
        buff += 21;
    }
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

    a = figure->ter[i].x[0];
    b = figure->ter[i].x[1];
    c = figure->ter[i].x[2];
    d = figure->ter[i].x[3];
    while (a != 0) //&& b != 0 && c != 0 && d != 0)
    {
        a -= 1;
        b -= 1;
        c -= 1;
        d -= 1;
    }
    figure->ter[i].x[0] = a;
    figure->ter[i].x[1] = b;
    figure->ter[i].x[2] = c;
    figure->ter[i].x[3] = d;
}

void    sShuffleY(t_global *figure, int i)
{
    int     a;
    int     b;
    int     c;
    int     d;

    a = figure->ter[i].y[0];
    b = figure->ter[i].y[1];
    c = figure->ter[i].y[2];
    d = figure->ter[i].y[3];
    while (a != 0 )//&& b != 0 && c != 0 && d != 0)
    {
        a -= 1;
        b -= 1;
        c -= 1;
        d -= 1;
    }
    figure->ter[i].y[0] = a;
    figure->ter[i].y[1] = b;
    figure->ter[i].y[2] = c;
    figure->ter[i].y[3] = d;
}
