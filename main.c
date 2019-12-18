
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
int main (int argc, char **argv)
{
	int fd;
	int result;
	char *line;
	int i;

	i =0;
	if(argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		while((result = get_next_line(fd, &line)) > 0)
		{
			printf("[%d] %s\n", result, line);
			free(line);
		}
	}
	return 0;
}


