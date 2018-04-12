/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykaplien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:03:01 by ykaplien          #+#    #+#             */
/*   Updated: 2018/03/22 19:08:09 by ykaplien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(char *dst, char *src, int len)
{
	int				offset;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	offset = 0;
	dst_c = (unsigned char*)dst;
	src_c = (unsigned char*)src;
	if (dst_c < src_c)
		while (len--)
		{
			*(dst_c + offset) = *(src_c + offset);
			offset++;
		}
	else
		while (len--)
			dst_c[len] = src_c[len];
	return (dst_c);
}
