
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:49:12 by ykaplien          #+#    #+#             */
/*   Updated: 2018/04/10 12:26:11 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct		s_elements
{
	int 			x[4];
	int 			y[4];
	char 			field;
}					t_elements;

typedef struct		s_global
{
	t_elements		*ter;
}					t_global;

int		            argCount(int argc, char **argv);
void                error(int a);
char		        *mRead(char **argv, char *buff);
int		            tValidation(char *buff);
int                 tNewl(char *buff);
int                 tSmbls(char *buff);
int                 tRelat(char *b);
int		            tCount(char *buff);
char                *validation(char *buff, int argc, char **argv);
void	            ft_bzero(void *s, int n);
void	            ft_putchar(char c);
void	            ft_putstr(char const *s);
int		            ft_strlen(char *s);
void                sFill(t_global *figure, char *buff);
void    			sShuffle(t_global *figure, char *buff);
void    			sShuffleX(t_global *figure, int i);
void    			sShuffleY(t_global *figure, int i);
char                **mCreate(int size);
int                 *mDot(char **map, int *yx);
int                 mCheck(t_elements figure, char **map, int *yx);
void                mSet(t_elements figure, char **map, int *yx, char letter);
char                **mCreate(int size);
void                backtracking(char *buff, t_global *figure);
void                mapSet(char **map, int size);
void                 print(char **map);
void                      print1(t_global *figure);


#endif
