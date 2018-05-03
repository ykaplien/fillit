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
    int             yx[2];
	char 			field;
}					t_elements;

typedef struct		s_global
{
	t_elements		*t;             //tetr
    int             size;
    int             yx[2];
    int             i;              //index
    int             z;              // tetr count
    char            **m;            //map
    char            **mCopy;        //map copy
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
void                print_check(t_global *figure, char *buff);

int                 mDot(t_global *f);
int                mCheck(t_global *f);
void                mSet(t_global *f);
char                **mCreateM(t_global *f);
void                cPlus(t_global *f);
void                print(t_global *f);  // print
void                print1(t_global *f, char *buff); // print

void                mapIter(t_global *figure);
void                initialization(t_global *figure, char *buff);
int                 backtracking(t_global *figure);
void                mCopyRewrite(t_global *f);
void                mRewrite(t_global *f);
void                mapCreate(t_global *f);
void                mapCopyCreate(t_global *f);
void                mapSet(t_global *f);
void                mCopySet(t_global *f);
void    mDel(t_global *figure);


#endif
