/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traktor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:06:54 by ykaplien          #+#    #+#             */
/*   Updated: 2018/04/10 12:26:24 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		    main(int argc, char **argv)
{
	char		*buff;
	t_global	*figure;

    if ((buff = validation(buff, argc, argv)))
    {
        figure = (t_global*)malloc(sizeof(t_global));
        initialization(figure, buff);
        sFill(figure, buff);
        sShuffle(figure, buff);
    }
	return (0);
}

void        initialization(t_global *figure, char **buff)
{
    figure->t = (t_elements*)malloc(sizeof(t_elements) * tCount(buff));
    figure->z = tCount(buff);
    figure->size = 2;
    figure->yx[0] = 0;
    figure->yx[1] = 0;
    figure->i = 0;
}
char        *validation(char *buff, int argc, char **argv)
{
    if (argCount(argc, argv))
        if ((buff = mRead(argv, buff)))
            if (tValidation(buff))
                return (buff);
    return (0);
}

void        print_check(t_global *figure, char *buff)
{
    int a = 0;
    int l = 0;
    int k = tCount(buff);
    char **map;

    map = mCreate(4);
    while (l < k)
    {
        a = 0;
        while (a < 4)
        {
            map[figure->t[l].y[a]][figure->t[l].x[a]] = figure->t[l].field;
            a++;
        }
//        print(map, 4);
//        mapSet(map, 4);
        l++;
    }
}
