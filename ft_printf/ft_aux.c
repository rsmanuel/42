#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	{
		while (width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_zero(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	if (params->zero && params->width && !params->minus)
	{
		while (width-- > 0)
			ft_putchar_fd('0', 1);
	}
}

void	ft_precision(t_struct *params, int len, char *str)
{
	int i;

	i = 0;
	if (params->width && !params->zero)
	{
		while (i < len - params->precision)
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
	}
	else if (params->width && params->zero)
	{
		while (i < len - params->precision)
		{
			ft_putchar_fd('0', 1);
			i++;
		}
	}
	i = 0;
	while (i < params->precision)
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
}
