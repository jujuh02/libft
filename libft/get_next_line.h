/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhaamid <juhaamid@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:15:57 by juhaamid          #+#    #+#             */
/*   Updated: 2023/12/05 09:44:24 by juhaamid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*separate_line(char *s);
char	*extractline(char *s);
char	*readline(int fd, char *line);
char	*ft_strchr(char *s, int c);
int		ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_strcpy(void *s1, void *s2, int n);
#endif