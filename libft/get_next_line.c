/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nparker <nparker@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:40:14 by nparker           #+#    #+#             */
/*   Updated: 2019/03/14 15:12:56 by nparker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			read_line(const int fd, char **str, char *buff, int read_fd)
{
	char			*temp;

	while ((read_fd = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[read_fd] = '\0';
		if (!(temp = ft_strjoin(str[fd], buff)))
			return (-1);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (read_fd);
}

static int			create_line(char **str, char **line, int fd)
{
	char			*tmp;
	int				len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, len)))
			return (-1);
		if (!(tmp = ft_strdup(str[fd] + len + 1)))
			return (-1);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else
	{
		if (!(*line = ft_strdup(str[fd])))
			return (-1);
		ft_strdel(&str[fd]);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static char		*str[65536];
	char			buff[BUFF_SIZE + 1];
	int				read_fd;

	read_fd = 0;
	if (fd < 0 || read(fd, buff, 0) < 0 || line == NULL)
		return (-1);
	if (str[fd] == NULL)
	{
		if (!(str[fd] = ft_strnew(0)))
			return (-1);
	}
	if (read_line(fd, str, buff, read_fd) < 0)
		return (-1);
	if (read_fd < 0)
		return (-1);
	if (read_fd == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	if (create_line(str, line, fd) == -1)
		return (-1);
	return (1);
}
