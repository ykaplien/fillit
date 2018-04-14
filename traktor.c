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

int		main(int argc, char **argv)
{
	char		*buff;
	t_elements	*figure;

    if (buff = validation(buff, argc, argv))
        if (sMalloc(figure, buff))
            sFill(&figure, buff);
            sShuffle(&figure, buff);

	return (0);
}

char    *validation(char *buff, int argc, char **argv)
{
    if (argCount(argc, argv))
        if ((buff = mRead(argv, buff)))
            if (tValidation(buff))
                return (buff);
    return (0);
}

int    sMalloc(t_elements *figure, char *buff)
{
    figure = (t_elements*)malloc(sizeof(t_elements) * tCount(buff));
    return (figure);
}
