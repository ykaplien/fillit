#include "fillit.h"

int    backtracking(t_global *figure)
{
    if (figure->i == figure->z)
        return (1);
    figure->yx[0] = 0;
    while (figure->yx[0] < figure->size)
//           && figure->yx[1] < figure->size)
    {
        figure->yx[1] = 0;
        while (figure->yx[1] < figure->size)
        {
            if (mDot(figure)) {
                //print(figure);
                figure->i++;
                if (!backtracking(figure)) {
                    figure->i--;
                    mDel(figure);
                } else {
                    return (1);
                }
            }
            figure->yx[1]++;
        }
        figure->yx[0]++;
    }
    return (0);
}
//    if (figure->i == figure->z)
//        return (1);
//    if (figure->i < figure->z)
//    {
//        if (mDot(figure))
//        {
//            figure->i++;
//            if (!backtracking(figure)) {
//                figure->i--;
//                figure->yx[0] = 0;
//                figure->yx[1] = 0;
//                backtracking(figure);
//            }
//        }
//        else
//        {
//            mapIter(figure);
//        }
//    }
//    return (0);

void    mapIter(t_global *figure)
{
    figure->size++;
//    mapCopyCreate(figure);
//    mCopyRewrite(figure);
    mapCreate(figure);
//    mRewrite(figure);
    figure->yx[0] = 0;
    figure->yx[1] = 0;
    figure->i = 0;
   // backtracking(figure);
}

void        mCopyRewrite(t_global *f)
{
    int x;
    int y;

    y = 0;
    while (y < f->size - 1)
    {
        x = 0;
        while (x < f->size - 1)
        {
            f->mCopy[y][x] = f->m[y][x];
            x++;
        }
        y++;
    }
}

void        mRewrite(t_global *f)
{
    int x;
    int y;

    y = 0;
    while (y < f->size)
    {
        x = 0;
        while (x < f->size)
        {
            f->m[y][x] = f->mCopy[y][x];
            x++;
        }
        y++;
    }
}

void    mapCreate(t_global *f)
{
    int     k;

    k = 0;
    if ((f->m = (char **)malloc(sizeof(char *) * (f->size + 1))))
    {
        while (k < f->size)
        {
            f->m[k] = (char *)malloc(sizeof(char) * f->size + 1);
            f->m[k][f->size] = '\0';
            k++;
        }
        f->m[f->size] = NULL;
    }
    mapSet(f);
}

void    mapCopyCreate(t_global *f)
{
    int     k;

    k = 0;
    if ((f->mCopy = (char **)malloc(sizeof(char *) * (f->size + 1))))
    {
        while (k < f->size)
        {
            f->mCopy[k] = (char *)malloc(sizeof(char) * f->size + 1);
            f->mCopy[k][f->size] = '\0';
            k++;
        }
        f->mCopy[f->size] = NULL;
    }
    mCopySet(f);
}

void    mapSet(t_global *f)
{
    int     k;
    int     l;

    k = 0;
    while (k < f->size)
    {
        l = 0;
        while (l < f->size)
        {
            f->m[k][l] = '.';
            //printf("%c", f->m[k][l]);
            l++;
        }
        k++;
    }
}

void    mCopySet(t_global *f)
{
    int     k;
    int     l;

    k = 0;
    while (k < f->size)
    {
        l = 0;
        while (l < f->size)
        {
            f->mCopy[k][l] = '.';
            //printf("%c", f->mCopy[k][l]);
            l++;
        }
        k++;
    }
}

int     mDot(t_global *f)
{
    int     x;
    int     y;
    char test;

    y = f->yx[0];
    while (y < f->size)
    {
        x = f->yx[1];
        while (x < f->size)
        {
            test = f->m[y][x];
            if (f->m[y][x] == '.')
            {
                f->yx[0] = y;
                f->yx[1] = x;
                if (f->yx[0] == f->size - 1
                    && f->yx[1] == f->size - 1 && f->i == 0)
                    return (0);
                if (mCheck(f))
                    return (1);
            }
            x++;
        }
        y++;
    }
    return (0);
}

int     mCheck(t_global *f)
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
    {
        mSet(f);
        return (1);
    }
    return (0);
}

void    mDel(t_global *figure)
{
    int     x;
    int     y;

    y = 0;
    while (y < figure->size)
    {
        x = 0;
        while (x < figure->size)
        {
            if (figure->m[y][x] == figure->t[figure->i].field)
                figure->m[y][x] = '.';
            x++;
        }
        y++;
    }
//    figure->m[figure->yx[0] + figure->t[figure->i].y[0]][figure->yx[1] + figure->t[figure->i].x[0]] = '.';
//    figure->m[figure->yx[0] + figure->t[figure->i].y[1]][figure->yx[1] + figure->t[figure->i].x[1]] = '.';
//    figure->m[figure->yx[0] + figure->t[figure->i].y[2]][figure->yx[1] + figure->t[figure->i].x[2]] = '.';
//    figure->m[figure->yx[0] + figure->t[figure->i].y[3]][figure->yx[1] + figure->t[figure->i].x[3]] = '.';
//    yx[0] = 0;
//    yx[1] = 0;
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

void    print(t_global *f)
{
    int l = 0;
    while (l < f->size)
    {
        printf("%s\n", f->m[l++]);
    }
    printf("\n");
}

void    print1(t_global *f, char *buff)
{
    int k;
    int l;

    k = 0;
    l = 0;
    while (l < tCount(buff))
    {
        k = 0;
        while (k < 4)
        {
            printf("%s", f->t[k].x[4]);
            k++;
        }
        l++;
    }
}