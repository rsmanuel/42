#include "libft/libft.h"
#include "ft_printf.h"

int	len_itox(unsigned long nb)
{
	int	len;

	len = 1;
	while (nb >= 16)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

char *ft_itox(unsigned long nb, t_struct *params)
{
	int	len;
	char *base;
	char *str;

	len = len_itox(nb);
	if (params->conversion == 'X')
		base = "0123456789ABCDEF";
	else if (params->conversion == 'x')
		base = "0123456789abcdef";
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len + 1] = '\0';
	while (len > 0)
	{
		str[len - 1] = base[nb % 16];
		nb /= 16;
		len--;
	}
	return (str);
}

void	print_x(va_list ap, t_struct *params, t_count *count)
{
	unsigned int nb;
	char *str;

	nb = va_arg(ap, unsigned int);
	str = ft_itox(nb, params);
	ft_putstr_fd(str, 1);
}