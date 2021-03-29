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
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len);
	ft_zero(params, len);
	ft_putchar_fd(c, 1);
	if (params->minus)
		ft_width(params, len);
}