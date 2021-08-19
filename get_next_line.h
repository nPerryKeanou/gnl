/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnowak <pnowak@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:23:02 by pnowak            #+#    #+#             */
/*   Updated: 2021/08/19 12:20:59 by pnowak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
int		ft_is_line(char *str);
int		ft_last_line(char *str);
char	*ft_join(char *str, char *str2, int ret);
char	*ft_new_line(char *str);
char	*ft_new_buf(char *str);
char	*ft_free_buf_tmp(char **buf, char **tmp);
char	*ft_return_line_change_buf(char **buf, char *tmp, int ret);
char	*ft_loop_read(int fd, int ret, char *buf, char *tmp);
char	*get_next_line(int fd);

#endif
