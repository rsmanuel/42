#include "get_next_line.h"

size_t  ft_strlen(const char *s)
{
    int i;

    i = 0;
    if (!s)
        return (0);
    while (s[i] != '\0')
        i++;
    return (i);
}

int     check_nl(char *buf_save)
{
    int i;

    i = 0;
    if(!buf_save)
        return (0);
    while (buf_save[i])
    {
        if (buf_save[i] == '\n')
            return (0);
        i++;
    }
    return (1);
}