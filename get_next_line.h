/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:58:56 by qgonzalv          #+#    #+#             */
/*   Updated: 2018/07/09 16:28:39 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 18
# include <fcntl.h>
# include <string.h>
# include "libft/libft.h"

// int		end_of_file(char **tmp, char **line, int rd);

char     *end_of_file(char **tmp, char **line, int *rd, int mode);
char    *ft_strjoinfree(char *s1, char *s2);
char	*readline(char *buf);
char	*tmp_inc(char *s1, char *s2);
int		get_next_line(const int fd, char **line);

#endif
