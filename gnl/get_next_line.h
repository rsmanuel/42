#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int			get_next_line(int fd, char **line);
char        *ft_strdup(const char *s1);

#endif