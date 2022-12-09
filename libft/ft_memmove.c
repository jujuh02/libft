/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:45:58 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/27 12:57:09 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sc;

	dest = (unsigned char *)dst;
	sc = (unsigned char *)src;
	if (dest == NULL && sc == NULL)
		return (NULL);
	if (dest > sc)
	{
		while (len > 0)
		{
			dest[len - 1] = sc[len - 1];
				len--;
		}
	}
	else
	{
		ft_memcpy(dst, src, len);
	}
	return (dst);
}

// a more stable memcpy.. if the dest is greater 
// than src len -1 takes care of overlapping 
