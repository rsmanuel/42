#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len)
{
	int	width;

	if (params->width < 0)
		params->width = -(params->width);
	width = params->width - len;
	{
		while (width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_zero(t_struct *params, int len)
{
	int	width;

	width = params->width - len;
	if (params->zero && params->width && !params->minus)
	{
		while (width-- > 0)
			ft_putchar_fd('0', 1);
	}
}

void	ft_precision(t_struct *params, int len, char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	if (params->width && !params->zero)
		c = ' ';
	else if (params->width && params->zero)
		c = '0';
	while (c && i < len - params->precision)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	i = 0;
	while (str[i] != '\0' && i < params->precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}
