#include "fillit.h"

int    backtacking(t_global *figure)
{
    while (figure->i < figure->z)
    {
        if (mDot(figure)) {
            figure->i++;
            if (backtacking(figure))
                return (1);
            else
                figure->i--;
        } else {
            mapIter(figure);
        }
    }
    return (0);
}

void    mapIter(t_global *figure)
{
    figure->mCopy = mRewrite(figure->m, figure->size, figure->size++);
    figure->m = mRewrite(figure->mCopy, figure->size, figure->size - 1);
    figure->yx[0] = 0;
    figure->yx[1] = 0;
}

int     mDot(t_global *f)
{
    int     x;
    int     y;

    y = f->yx[0];
    while (y < f->size)
    {
        x = f->yx[1];
        while (x < f->size)
        {
            if (f->m[y][x] == '.')
            {
                f->yx[0] = y;
                f->yx[1] = x;
                if (f->yx[0] == f->size - 1
                    && f->yx[1] == f->size - 1 && f->i == 0)
                    return (0);
                mCheck(f);
//                return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

void     mCheck(t_global *f)
{
    int     count;

    count = 0;
    if (f->yx[0] + f->t[f->i].y[0] < f->size
        && f->yx[1] + f->t[f->i].x[0] < f->size
        && f->m[f->yx[0] + f->t[f->i].y[0]][f->yx[1] + f->t[f->i].x[0]] == '.')
        count++;
    if (f->yx[0] + f->t[f->i].y[1] < f->size
        && f->yx[1] + f->t[f->i].x[1] < f->size
        && f->m[f->yx[0] + f->t[f->i].y[1]][f->yx[1] + f->t[f->i].x[1]] == '.')
        count++;
    if (f->yx[0] + f->t[f->i].y[2] < f->size
        && f->yx[1] + f->t[f->i].x[2] < f->size
        && f->m[f->yx[0] + f->t[f->i].y[2]][f->yx[1] + f->t[f->i].x[2]] == '.')
        count++;
    if (f->yx[0] + f->t[f->i].y[3] < f->size
        && f->yx[1] + f->t[f->i].x[3] < f->size
        && f->m[f->yx[0] + f->t[f->i].y[3]][f->yx[1] + f->t[f->i].x[3]] == '.')
        count++;
    if (count == 4)
        mSet(f);
}

void    mDel(t_elements f, char **m, int *yx, int i)
{
    m[yx[0] + f.y[0]][yx[1] + f.x[0]] = '.';
    m[yx[0] + f.y[1]][yx[1] + f.x[1]] = '.';
    m[yx[0] + f.y[2]][yx[1] + f.x[2]] = '.';
    m[yx[0] + f.y[3]][yx[1] + f.x[3]] = '.';
    yx[0] = 0;
    yx[1] = 0;
}
void    mSet(t_global *f)
{
    f->m[f->yx[0] +  f->t[f->i].y[0]][f->yx[1] + f->t[f->i].x[0]] = f->t[f->i].field;
    f->m[f->yx[0] +  f->t[f->i].y[1]][f->yx[1] + f->t[f->i].x[1]] = f->t[f->i].field;
    f->m[f->yx[0] +  f->t[f->i].y[2]][f->yx[1] + f->t[f->i].x[2]] = f->t[f->i].field;
    f->m[f->yx[0] +  f->t[f->i].y[3]][f->yx[1] + f->t[f->i].x[3]] = f->t[f->i].field;
    f->yx[0] = 0;
    f->yx[1] = 0;
}

char    **mCreate(t_global *f)
{
    int     k;

    k = 0;
    if (f->m = (char **)malloc(sizeof(char *) * (f->size + 1)))
    {
        while (k < f->size)
        {
            f->m[k] = (char *)malloc(sizeof(char) * f->size + 1);
            f->m[k][f->size] = '\0';
            k++;
        }
        f->m[f->size] = NULL;
    }
    mSet(f);
    return (f->m);
}

void    cPlus(t_global *f)
{
    if (f->yx[1] == f->size - 1)
    {
        f->yx[0] += 1;
        f->yx[1] = 0;
    }
    else
        f->yx[1] += 1;
}


char    **mRewrite(t_global *f, int size1, int size2)
{
    int x;
    int y;

    y = 0;
    f->mCopy = mCreate(size1);
    while (y < size2)
    {
        x = 0;
        while (x < size2)
        {
            f->mCopy[y][x] = f->m[y][x];
            x++;
        }
        y++;
    }
    return (f->mCopy);
}

void    mapSet(t_global *f)
{
    int     x;
    int     y;

    y = 0;
    while (y < f->size)
    {
        x = 0;
        while (x < f->size)
        {
            f->m[y][x] = '.';
            x++;
        }
        y++;
    }
}

void    print(t_global *f)
{
    int l = 0;
    while (l < f->size)
    {
        printf("%s\n", f->m[l++]);
    }
    printf("\n");
}
