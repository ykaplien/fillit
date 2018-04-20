#include "fillit.h"

int     *mDot(char **map, int *yx)
{
    int     x;
    int     y;

    x = yx[1];
    y = yx[0];
    while (map[y][x])
    {
        y = 0;
        while (map[y][x])
        {
            if (map[y][x] == '.')
            {
                yx[0] = y;
                yx[1] = x;
                return (yx);
            }
            y++;
        }
        x++;
    }
    print(map);
    return (0);
}

int     mCheck(t_elements f, char **map, int *yx)
{
    int     count;

    count = 0;
    if (map[yx[0] + f.y[0]][yx[1] + f.x[0]] && map[yx[0] + f.y[0]][yx[1] + f.x[0]] == '.')
        count++;
    if (map[yx[0] + f.y[1]][yx[1] + f.x[1]] && map[yx[0] + f.y[1]][yx[1] + f.x[1]] == '.')
        count++;
    if (map[yx[0] + f.y[2]][yx[1] + f.x[2]] && map[yx[0] + f.y[2]][yx[1] + f.x[2]] == '.')
        count++;
    if (map[yx[0] + f.y[3]][yx[1] + f.x[3]] && map[yx[0] + f.y[3]][yx[1] + f.x[3]] == '.')
        count++;
    if (count == 4)
        return (1);
    return (0);
}



void    mSet(t_elements figure, char **map, int *yx, char letter)
{
    map[yx[0] + figure.y[0]][yx[1] + figure.x[0]] = letter;
    map[yx[0] + figure.y[0]][yx[1] + figure.x[0]] = letter;
    map[yx[0] + figure.y[0]][yx[1] + figure.x[0]] = letter;
    map[yx[0] + figure.y[0]][yx[1] + figure.x[0]] = letter;
}

char    **mCreate(int size)
{
    char    **map;
    int     k;

    k = 0;
    if (map = (char **)malloc(sizeof(char *) * (size + 1)))
    {
        while (k < size)
        {
            map[k] = (char *)malloc(sizeof(char) * size + 1);
            map[k][size] = '\0';
            k++;
        }
        map[size] = NULL;
    }
    mapSet(map, size);
    return (map);
}

//void    cPlus(int *yx)
//{
//    yx[0] += 1;
//    yx[1] += 1;
//}

void    backtracking(char *buff, t_global *figure)
{
    int     size;
    int     yx[2];
    int     i;
    char    **map;

    size = 2;
    i = 0;
    yx[0] = 0;
    yx[1] = 0;
    map = mCreate(size);
    while (i < tCount(buff))
    {

        if (mDot(map, yx))
            if (mCheck(figure->ter[i], map, yx))
                mSet(figure->ter[i], map, yx, figure->ter[i].field);
        else
                map = mCreate(++size);
    }
}

void    mapSet(char **map, int size)
{
    int     x;
    int     y;

    x = 0;
    y = 0;
    while (y < size)
    {
        x = 0;
        while (x < size)
        {
            map[y][x] = '.';
            x++;
        }
        y++;
    }
}

void    print(char **map)
{
    int l = 0;
    while (l < 3)
    {
        printf("%s", map[l++]);
    }
}
void    print1(t_global *figure)
{
    printf("x: %d %d %d %d", figure->ter[0].x[0], figure->ter[0].x[1], figure->ter[0].x[2], figure->ter[0].x[3]);
    printf("y: %d %d %d %d", figure->ter[0].y[0], figure->ter[0].y[1], figure->ter[0].y[2], figure->ter[0].y[3]);
}