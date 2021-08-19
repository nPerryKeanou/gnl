/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnowak <pnowak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:22:20 by pnowak            #+#    #+#             */
/*   Updated: 2021/08/19 12:21:37 by pnowak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free_buf_tmp(char **buf, char **tmp)
{
	if (*buf)
		free(*buf);
	*buf = NULL;
	if (*tmp)
		free(*tmp);
	*tmp = NULL;
	return (NULL);
}

char	*ft_join(char *str, char *str2, int ret)
{
	int			i;
	int			j;
	char		*tmp;

	i = -1;
	j = -1;
	if (str == NULL)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	tmp = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(str2) + 1));
	if (!tmp)
		return (NULL);
	while (str[++i])
		tmp[i] = str[i];
	while (str2[++j] && j < ret)
		tmp[i + j] = str2[j];
	tmp[i + j] = '\0';
	free(str);
	return (tmp);
}

char	*ft_return_line_change_buf(char **buf, char *tmp, int ret)
{
	char	*line;

	line = ft_new_line(*buf);
	if (!line)
		return (ft_free_buf_tmp(&*buf, &tmp));
	if (ret == 0 && (!buf || *buf[0] == '\0'))
	{
		if (line)
			free(line);
		return (ft_free_buf_tmp(&*buf, &tmp));
	}
	if (tmp)
		free(tmp);
	*buf = ft_new_buf(*buf);
	if (!buf)
	{
		if (line)
			free(line);
		return (ft_free_buf_tmp(&*buf, &tmp));
	}
	return (line);
}

char	*ft_loop_read(int fd, int ret, char *buf, char *tmp)
{
	while (ft_is_line(buf) < 0 && ret > 0)
	{
		ret = read(fd, tmp, BUFFER_SIZE);
		if (ret)
		{
			buf = ft_join(buf, tmp, ret);
			if (!buf)
				return (ft_free_buf_tmp(&buf, &tmp));
		}
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	int			ret;
	char		*tmp;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free_buf_tmp(&buf, &tmp));
	tmp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (ft_free_buf_tmp(&buf, &tmp));
	ret = read(fd, tmp, BUFFER_SIZE);
	if (ret == -1)
		return (ft_free_buf_tmp(&buf, &tmp));
	tmp[ret] = '\0';
	if (ret)
	{
		buf = ft_join(buf, tmp, ret);
		if (!buf)
			return (ft_free_buf_tmp(&buf, &tmp));
	}
	else if (!ret && (!buf))
		return (ft_free_buf_tmp(&buf, &tmp));
	buf = ft_loop_read(fd, ret, buf, tmp);
	if (ret == 0 && (!buf || buf[0] == '\0'))
		return (ft_free_buf_tmp(&buf, &tmp));
	return (ft_return_line_change_buf(&buf, tmp, ret));
}
