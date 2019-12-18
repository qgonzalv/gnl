#include "get_next_line.h"

char    *ft_strsub(char const *s, unsigned int start, size_t len)
{
        int             count;
        char    *nstr;

        if (s == NULL)
                return (NULL);
        if ((nstr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
                return (NULL);
        count = 0;
        while (len > (size_t)count && s[start + count])
        {
                nstr[count] = s[start + count];
                count++;
        }
        nstr[count] = '\0';
        return (nstr);
}

char    *ft_strsubin(char *out, char **in, char c)
{
        char    *tmp;

        *in = ft_strsub(out, 0, ft_strchri(out, c));
        tmp = ft_strsub(out, ft_strchri(out, c) + 1, ft_strlen(out));
        free(out);
        out = ft_strdup(tmp);
        free(tmp);
        return (out);
}

int             ft_strchri(char *str, char c)
{
        int count;

        count = 0;
        while (str[count])
        {
                if (str[count] == c)
                        return (count);
                count++;
        }
        return (-1);
}

char    *ft_strdup(const char *s1)
{
        int             len;
        char    *dup;
        int             count;

        count = 0;
        len = ft_strlen(s1);
        dup = (char*)malloc(((sizeof(char) * len) + 1));
        if (dup == NULL)
                return (NULL);
        while (count < len)
        {
                dup[count] = s1[count];
                count++;
        }
        dup[count] = s1[count];
        return (dup);
}

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*str[OPEN_MAX + 1];

	if (!(line) || fd < 0 || fd > OPEN_MAX)
		return (-1);
	if (fd > -1 && str[fd] && ft_strchri(str[fd], '\n') != -1)
	{
		str[fd] = ft_strsubin(str[fd], line, '\n');
		return (1);
	}
	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		str[fd] = ((!str[fd]) ? ft_strdup(buff) : ft_strljoin(str[fd], buff));
		return (get_next_line(fd, line));
	}
	if (ret == 0 && str[fd] && str[fd][0])
	{
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = NULL;
		return (1);
	}
	return (ret > 0 ? 1 : ret);
}
