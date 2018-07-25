/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qgonzalv <qgonzalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 14:50:27 by qgonzalv          #+#    #+#             */
/*   Updated: 2018/07/09 16:50:37 by qgonzalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include<stdio.h>

int main (int argc, char **argv)
{
	int fd;
	int gnl_result;
	char *line;
	int i ;
	i = 0;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while((gnl_result = get_next_line(fd, &line)) > 0)
		{
			//ft_putnbr(gnl_result);
			printf("  %s\n", line);
			free(line);
		}
			//ft_putnbr(gnl_result);
	}
	return (0);
}
