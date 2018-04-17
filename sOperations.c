#include "fillit.h"

int     mSize(int num)
{
    int     res;
    int     i;

    res = num * 4;
    i = 2;
    while (i * i <= res)
        i++;
    if (i * i == res)
        return (res);
    i++;
    return (i * i);
}

void    sFill(t_global *figure, char *buff)
{
    int     ind;
    int     i;
    char    letter;

    i = 0;
    letter = 'A';
    while (*buff)
    {
        ind = 0;
        figure->ter[i].tetr = (char *)malloc(sizeof(char) * 21);
        while (ind <= 20)
        {
            figure->ter[i].tetr[ind] = buff[ind];
            ind++;
        }
        figure->ter[i].tetr[21] = '\0';
        figure->ter[i].field = letter++;
        i++;
        buff += 21;
    }
}

t_global  *sShuffle(t_global *figure, char *buff)
{
    int     i;

    i = 0;
    while (i < tCount(buff))
    {
        sShuffleProcess(figure->ter[i].field, figure->ter[i].tetr);
        i++;
    }
    return (figure);
}

void    sShuffleProcess(char field, char *string)
{
    int     ind;
    int     xShift;
    int     yShift;

    ind = 0;
    xShift = sShuffleX(string);
    yShift = sShuffleY(string);
    while (string[ind])
    {
        if (string[ind] == '#')
        {
            string[ind] = '.';
            string[ind - (xShift + (5 * yShift))] = field;
        }
        ind++;
    }
}

int     sShuffleY(char *string)
{
    int     shift;
    int     ind;

    ind = 0;
    while (string[ind] != '#')
        ind++;
    shift = ind / 5;
    while (ind < 20)
    {
        if (string[ind] == '#')
            if (shift > (ind / 5))
                shift = ind / 5;
        ind++;
    }
    return (shift);
}

int     sShuffleX(char *string)
{
    int     shift;
    int     ind;

    ind = 0;
    while (string[ind] != '#')
        ind++;
    shift = ind % 5;
    while (ind < 20)
    {
        if (string[ind] == '#')
            if (shift > (ind % 5))
                shift = ind % 5;
        ind++;
    }
    return (shift);
}