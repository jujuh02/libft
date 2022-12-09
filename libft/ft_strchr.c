/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 14:51:57 by juhaamid          #+#    #+#             */
/*   Updated: 2022/10/31 12:35:43 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (unsigned char) c)
	{
		if (!s[i])
			return (0);
		i++;
	}
	return ((char *)s + i);
}
// searches for first occurance of c
// prints everything after
