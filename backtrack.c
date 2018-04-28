#include "fillit.h"

int     *mDot(char **map, int *yx, int n)
{
    int     x;
    int     y;

    y = yx[0];
    while (y < n)
    {
        x = yx[1];
        while (x < n)
        {
            if (map[y][x] == '.')
            {
                yx[0] = y;
                yx[1] = x;
                if (yx[0] == n - 1 && yx[1] == n - 1)
                    return (0);
                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int     mCheck(t_elements f, char **map, int *yx, int n)
{
    int     count;

    count = 0;
    if (yx[0] + f.y[0] < n && yx[1] + f.x[0] < n && map[yx[0] + f.y[0]][yx[1] + f.x[0]] == '.')
        count++;
    if (yx[0] + f.y[1] < n && yx[1] + f.x[1] < n && map[yx[0] + f.y[1]][yx[1] + f.x[1]] == '.')
        count++;
    if (yx[0] + f.y[2] < n && yx[1] + f.x[2] < n && map[yx[0] + f.y[2]][yx[1] + f.x[2]] == '.')
        count++;
    if (yx[0] + f.y[3] < n && yx[1] + f.x[3] < n && map[yx[0] + f.y[3]][yx[1] + f.x[3]] == '.')
        count++;
    if (count == 4)
        return (1);
    return (0);
}



void    mSet(t_elements figure, char **map, int *yx, char letter)
{
    map[yx[0] + figure.y[0]][yx[1] + figure.x[0]] = letter;
    map[yx[0] + figure.y[1]][yx[1] + figure.x[1]] = letter;
    map[yx[0] + figure.y[2]][yx[1] + figure.x[2]] = letter;
    map[yx[0] + figure.y[3]][yx[1] + figure.x[3]] = letter;
    yx[0] = 0;
    yx[1] = 0;
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

void    cPlus(int *yx, int size)
{
    if (yx[1] == size - 1)
    {
        yx[0] += 1;
        yx[1] = 0;
    }
    else
        yx[1] += 1;
}

void    backtracking(char *buff, t_global *figure)
{
    int     size;
    int     yx[2];
    int     i;
    char    **map;
    char    **mCopy;

    size = 2;
    i = 0;
    yx[0] = 0;
    yx[1] = 0;
    map = mCreate(size);
    while (i < tCount(buff))
    {
        if (mDot(map, yx, size))
            if (mCheck(figure->ter[i], map, yx, size))
            {
                mSet(figure->ter[i], map, yx, figure->ter[i++].field);
                print(map,size);
            }
            else
                cPlus(yx, size);
        else
        {
            mCopy = mRewrite(map, size, size++);
            map = mRewrite(mCopy, size, size - 1);
            yx[0] = 0;
            yx[1] = 0;
        }
    }
    print(map,size);
}

char    **mRewrite(char **map, int size1, int size2)
{
    int x;
    int y;
    char **mCopy;

    y = 0;
    mCopy = mCreate(size1);
    while (y < size2)
    {
        x = 0;
        while (x < size2)
        {
            mCopy[y][x] = map[y][x];
            x++;
        }
        y++;
    }
    return (mCopy);
}

void    mapSet(char **map, int size)
{
    int     x;
    int     y;

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

void    print(char **map, int size)
{
    int l = 0;
    while (l < size)
    {
        printf("%s\n", map[l++]);
    }
    printf("\n");
}
void    print1(t_elements figure)
{
    int a  = figure.x[0];
    int b  = figure.y[0];
    int a1 = figure.x[1];
    int b1 = figure.y[1];
    int a2 = figure.x[2];
    int b2 = figure.y[2];
    int a3 = figure.x[3];
    int b3 = figure.y[3];
    printf("x: %d %d %d %d\n", a, a1, a2, a3);
    printf("y: %d %d %d %d\n", b, b1, b2, b3);
}