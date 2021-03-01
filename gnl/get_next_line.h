#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char        *ft_strjoin(char const *s1, char const *s2);
int         findnl(char *new_line);
int	        get_next_line(int fd, char **line);
int			ft_strlen(char const *str);

#endif