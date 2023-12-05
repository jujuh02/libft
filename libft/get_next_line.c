/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:10:19 by juhaamid          #+#    #+#             */
/*   Updated: 2023/12/05 09:45:04 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extractline(char *s)
{
	char	*new_buff;
	int		idx;
	int		j;

	idx = 0;
	while (s[idx] && s[idx] != '\n')
		idx++;
	if (!s[idx] || !s[idx + 1])
	{
		free(s);
		return (NULL);
	}
	if (s[idx] == '\n' || s[idx] == 0)
	{
		new_buff = (char *)malloc(sizeof(char) * (ft_strlen(s) - idx + 1));
		if (!new_buff)
			return (NULL);
	}
	idx++;
	j = 0;
	while (s[idx])
		new_buff[j++] = s[idx++];
	new_buff[j] = '\0';
	free(s);
	return (new_buff);
}

char	*separate_line(char *s)
{
	char	*line;
	int		idx;

	idx = 0;
	if (!s[idx])
		return (NULL);
	while (s[idx] != '\n' && s[idx])
		idx++;
	idx++;
	line = (char *)malloc(sizeof(char) * (idx + 1));
	if (!line)
		return (NULL);
	line = ft_strcpy(line, s, idx + 1);
	line[idx] = '\0';
	return (line);
}

char	*readline(int fd, char *line)
{
	char	*buff;
	int		bytes;

	buff = malloc (((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line[1024];
	char		*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483646)
		return (0);
	line[fd] = readline(fd, line[fd]);
	if (!line[fd])
		return (NULL);
	buff = separate_line(line[fd]);
	line[fd] = extractline(line[fd]);
	return (buff);
}
