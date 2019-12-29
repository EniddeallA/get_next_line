/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:48:20 by akhalid           #+#    #+#             */
/*   Updated: 2019/12/29 02:42:27 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char **str)
{
	char	*buff;
	int		nbytes;
	char	*t;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (*str == NULL)
		*str = ft_strdup("");
	while (!(ft_strchr(*str, '\n')))
	{
		if ((nbytes = read(fd, buff, BUFFER_SIZE)) < 0)
			return (0);
		buff[nbytes] = '\0';
		t = ft_strjoin(*str, buff);
		free(*str);
		*str = t;
		if (nbytes == 0)
			break ;
	}
	free(buff);
	return (*str);
}

int		get_next_line(int fd, char **line)
{
	static	char	*str[1024];
	char			*temp;
	char			*t;

	if (!line || !(str[fd] = ft_read(fd, &str[fd])))
		return (-1);
	if ((temp = ft_strchr(str[fd], '\n')))
	{
		t = str[fd];
		*line = ft_substr(str[fd], 0, temp - str[fd]);
		str[fd] = ft_strdup(str[fd] + (temp - str[fd]) + 1);
		free(t);
		return (1);
	}
	else
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (0);
	}
}
