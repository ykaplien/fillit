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
    int i = 0;
    int j = 0;

    if (buff = validation(buff, argc, argv))
    {
        figure = (t_global*)malloc(sizeof(t_global));
        figure->ter = (t_elements*)malloc(sizeof(t_elements) * tCount(buff));
        sFill(figure, buff);
        sShuffle(figure, buff);
    }

	return (0);
}

char        *validation(char *buff, int argc, char **argv)
{
    if (argCount(argc, argv))
        if ((buff = mRead(argv, buff)))
            if (tValidation(buff))
                return (buff);
    return (0);
}
