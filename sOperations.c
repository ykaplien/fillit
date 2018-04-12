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

void    sFill(t_elements *figure, char *buff)
{
    int     ind;
    int     i;
    char    letter;

    i = 0;
    letter = 'A';
    while (*buff)
    {
        ind = 0;
        while (ind <= 20)
        {
            figure[i].tetr[ind] = buff[ind];
            ind++;
        }
        figure[i].tetr[21] = '\0';
        printf("%s", figure[i].tetr);
        figure[i].field = letter++;
        i++;
        buff += 21;
    }
}

void    sShuffle(t_elements *figure, char *buff)
{
    int     i;
    int     ind;
    int     hashs;

    i = 0;
    ind = 0;
    while (i < tCount(buff))
    {
        hashs = 0;
        while(figure[i].tetr[ind] != '#' && figure[i].tetr[ind])
            ind++;
        ft_memmove(figure[i].tetr[0], figure[i].tetr[ind], 20 - ind);
        ind = 0;
        while (figure[i].tetr[ind])
        {
            while (figure[i].tetr[ind++] == '#' && hashs <= 4)
                hashs++;
            if (figure[i].tetr[ind] == '#')
                figure[i].tetr[ind] = '.';
            ind++;
        }
        i++;
    }
}
