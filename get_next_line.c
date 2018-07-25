/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:57:30 by qgonzalv          #+#    #+#             */
/*   Updated: 2018/07/09 18:17:10 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char			*read_line(char *buf)
{
	char		*res;
	int			i;

	i = 0;
	while (buf[i] != '\n' && buf[i] != '\0')
		i++;
	res = (char *)malloc(sizeof(char *) * (i + 1));
	res = ft_strncpy(res, buf, i);
	res[i] = '\0';
	return (res);
}

char             *end_of_file(char **tmp, char **line, int *rd, int mode)
{
    char        *s2;

    if (mode == 0)
    {
       if (*rd == 0 && ft_strlen(*tmp) > 0)
       {
		   	ft_putendl("/////////////endoffile?/////////////////////");
           *line = ft_strdup(*tmp);
           free(*tmp);
           *tmp = NULL;
           *rd = 1;
       }
       return (NULL);
    }
   s2 = ft_strdup(*line);
   return (ft_strjoinfree(*tmp, s2));
}

char			*ft_strjoinfree(char *s1, char *s2)
{
	char		*final;
	int			i;
	int			len;
	int			j;

	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	i = -1;
	final = malloc(sizeof(final) * len);
	if (final == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		final[i] = s1[i];
	while (s2[j] != '\0')
		final[i++] = s2[j++];
	free(s1);
	free(s2);
	final[i] = '\0';
	return (final);
}

int			not_into_the_line(char *tmp, int fd, char* buf, char **line )
{
	int rd;
	printf("%s \n", buf);
	if ((rd = read(fd, buf, BUFF_SIZE)) < 1)
	{
		ft_putnbr(rd);
		ft_putendl("/////////////tu crache la  boucle if avec rd < 1?/////////////////////");
		free(buf);
		// ft_strdel(&buf);
		end_of_file(&tmp, line, &rd, 0);
		return (rd);
	}
	ft_putendl("et ici");
	buf[rd] = '\0';
	tmp = end_of_file(&tmp, &buf, &rd, 1);
	printf("len de tmp dans mot into quand on est pas a la fin du fichier : %zu \n", ft_strlen(tmp));
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	// int			rd;
	char		*buf;
	char		*tmp;
	int			i;

	i = 0;
	if (fd < 0 || fd == 2 || !line || BUFF_SIZE <= 0)
		return (-1);
	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (!str)
		str = ft_memalloc(BUFF_SIZE + 1);
	tmp = ft_strncpy(ft_memalloc(BUFF_SIZE), str, BUFF_SIZE);
	ft_bzero(str, BUFF_SIZE + 1);
	//rd = 0;
	while (!(ft_strchr(tmp, '\n')))
		not_into_the_line(tmp,fd,buf,line);
	// {
	// 	if ((rd = read(fd, buf, BUFF_SIZE)) < 1)
	// 	{
	// 		ft_putnbr(rd);
	// 		free(buf);
	// 		end_of_file(&tmp, line, &rd, 0);
	// 		return (rd);
	// 	}
	// 	ft_putnbr(rd);
	// 	buf[rd] = '\0';
	// 	tmp = end_of_file(&tmp, &buf, &rd, 1);
	// }
	*line = read_line(tmp);
	if (ft_strchr(tmp, '\n'))
		str = ft_strncpy(str, ft_strchr(tmp, '\n') + 1, BUFF_SIZE);
	// ft_putendl("/////////////tu crache la ?/////////////////////");
	free(tmp);
	// ft_putendl("/////////////YOUHOU tu crache la ?/////////////////////");
	ft_strdel(&buf);// free(buf);
	ft_putendl("/////////////YOUHOU EHOOOOOO tu crache la ?/////////////////////");
	return (1);
}
