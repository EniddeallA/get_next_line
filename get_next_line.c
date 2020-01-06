/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalid <akhalid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:48:20 by akhalid           #+#    #+#             */
/*   Updated: 2019/11/02 21:57:01 by akhalid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *str)
{
	char	*buff;
	int		nbytes;
	char	*t;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (0);
	if (str == NULL)
		str = ft_strdup("");
	while (!(ft_strchr(str, '\n')))
	{
		if ((nbytes = read(fd, buff, BUFFER_SIZE)) < 0)
			return (0);
		buff[nbytes] = '\0';
		t = ft_strjoin(str, buff);
		free(str);
		str = t;
		if (nbytes == 0)
			break ;
	}
	free(buff);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static	char	*str;
	char			*temp;
	char			*t;

	if (!line || !(str = ft_read(fd, str)))
		return (-1);
	if ((temp = ft_strchr(str, '\n')))
	{
		t = str;
		*line = ft_substr(str, 0, temp - str);
		str = ft_strdup(str + (temp - str) + 1);
		free(t);
		return (1);
	}
	else
	{
		*line = ft_strdup(str);
		free(str);
		str = NULL;
		return (0);
	}
}
