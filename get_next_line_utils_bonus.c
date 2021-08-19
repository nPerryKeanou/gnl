/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnowak <pnowak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:22:42 by pnowak            #+#    #+#             */
/*   Updated: 2021/08/19 12:21:19 by pnowak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_is_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_last_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-2);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_new_line(char *str)
{
	int			i;
	int			len_is_line;
	char		*tmp;

	i = 0;
	len_is_line = ft_last_line(str);
	if (len_is_line < 0)
		return (NULL);
	tmp = malloc(sizeof(char) * (len_is_line + 1));
	if (!tmp)
		return (NULL);
	while (str[i] && i < len_is_line)
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_new_buf(char *str)
{
	int			i;
	int			len_is_line;
	int			len_final;
	char		*tmp;

	if (str == NULL)
		str = malloc(sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	len_is_line = ft_last_line(str);
	len_final = ft_strlen(str) - len_is_line;
	tmp = malloc(sizeof(char) * (len_final + 1));
	if (!tmp)
		return (NULL);
	len_is_line = len_is_line + 1;
	while (str[len_is_line] && i < len_final)
	{
		tmp[i] = str[len_is_line];
		i++;
		len_is_line++;
	}
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
