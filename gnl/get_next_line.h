#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdlib.h>

int get_next_line(int fd, char **line);
size_t  ft_strlen(const char *s);
int check_nl(char *buf_save);
char	*make_buf_save(char *buf_save, char *buf);

#endif