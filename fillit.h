
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
	char            *tetr;
	char 			field;
}					t_elements;

int		            argCount(int argc, char **argv);
void                error(int a);
char		        *mRead(char **argv, char *buff);
int		            tValidation(char *buff);
int                 tNewl(char *buff);
int                 tSmbls(char *buff);
int                 tRelat(char *b);
int		            tCount(char *buff);
int                 validation(char *buff, int argc, char **argv);
int                 sMalloc(t_elements *figure, char *buff);
void	            ft_bzero(void *s, int n);
void	            ft_putchar(char c);
void	            ft_putstr(char const *s);
int		            ft_strlen(char *s);
int                 mSize(int num);
void            	*ft_memmove(char *dst, char *src, int len);

#endif
