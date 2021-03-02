#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len + 1);
	if (s2 == NULL)
		return (0);
	ft_strlcpy(s2, s1, len + 1);
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		k;

	if (!s1 || !s2)
		return (0);
	i = 0;
	k = 0;
	if (!(s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
	{
		s3[k] = s1[i];
		i++;
		k++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		s3[k] = s2[i];
		i++;
		k++;
	}
	s3[k] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	newc;

	newc = (char)c;
	str = (char *)s;
	while (*str)
	{
		if (*str == newc)
			return (str);
		str++;
	}
	if (newc == *str)
		return (str);
	return (NULL);
}