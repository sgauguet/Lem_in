/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 10:55:36 by sgauguet          #+#    #+#             */
/*   Updated: 2018/06/12 11:07:19 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*select_first_line(char *str)
{
	char	*first_line;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!(first_line = ft_strnew(i)))
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		first_line[i] = str[i];
		i++;
	}
	first_line[i] = '\0';
	return (first_line);
}

static char	*ft_delete_line(char *str)
{
	char	*result;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (ft_strnew(0));
	}
	result = ft_strnew(ft_strlen(str) - i);
	if (!result)
		return (NULL);
	ft_strcpy(result, &str[i + 1]);
	free(str);
	return (result);
}

int			ft_stop(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char		*ft_check_gnl(int fd, char **line)
{
	char *buf;

	buf = NULL;
	if (fd < 0 || fd >= FD || line == NULL || BUFF_SIZE < 1
			|| !(buf = ft_strnew(BUFF_SIZE + 1)) || read(fd, buf, 0) == -1)
	{
		if (buf)
			free(buf);
		return (NULL);
	}
	return (buf);
}

int			get_next_line(const	int fd, char **line)
{
	static char *result[FD];
	char		*tmp;
	char		*buf;
	int			ret;

	if (!(buf = ft_check_gnl(fd, line)))
		return (-1);
	if (!result[fd])
		result[fd] = ft_strnew(0);
	while (ft_stop(result[fd]) != 1 && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = result[fd];
		result[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	ft_strdel(&buf);
	if (result[fd][0] == '\0')
		return (0);
	*line = select_first_line(result[fd]);
	result[fd] = ft_delete_line(result[fd]);
	return (1);
}
