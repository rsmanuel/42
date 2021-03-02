#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int			get_next_line(int fd, char **line);
char        *ft_strdup(const char *s1);
char	    *ft_strjoin(char const *s1, char const *s2);
char	    *ft_strchr(const char *s, int c);
char	    *ft_substr(char const *s, unsigned int start, size_t len);
int	        ft_strlen_nl(char **save_line);
int	        return_values(char **save_line, char **line, int ret);
size_t	    ft_strlen(const char *s);
size_t	    ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif