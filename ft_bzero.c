/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 20:26:52 by ykaplien          #+#    #+#             */
/*   Updated: 2018/04/10 12:10:45 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_bzero(void *s, int n)
{
	unsigned char *res_point;

	res_point = (unsigned char *)s;
	while (n--)
		*res_point++ = '\0';
}