#include "libft/libft.h"
#include "ft_printf.h"

void	print_c(va_list ap, t_struct *params)
{
	char c;
	int len;

	c = va_arg(ap, int);
	len = 1;
	print_c_aux(params, len, c);
}

void	print_c_aux(t_struct *params, int len, char c)
{
	ft_zero_c(params, len);
	ft_width_c(params, len);
	ft_putchar_fd(c, 1);
	ft_minus_c(params, len);
	}

void	ft_width_c(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	if (params->width && !params->minus && !params->zero)
	{
		while(width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_zero_c(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	if (params->zero && params->width && !params->minus)
	{
		while(width-- > 0)
			ft_putchar_fd('0', 1);
	}
}

void	ft_minus_c(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	if(params->width && params->minus)
	{
		while(width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}