#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100
# define OPEN_MAX 41
# include <limits.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int				get_next_line(const int fd, char **line);
size_t				ft_strlen(const char *str);
char   				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strsubin(char *out, char **in, char c);
int 			        ft_strchri(char *str, char c);
char				*ft_strdup(const char *s1);
char 				*ft_strljoin(char *s1, char *s2);
char				*ft_strjoin(char const *s1, char const *s2);






#endif
