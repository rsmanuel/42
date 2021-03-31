#include "libft/libft.h"
#include "ft_printf.h"

void	print_c(va_list ap, t_struct *params, t_count *count)
{
	char	c;
	int		len;

	c = va_arg(ap, int);
	len = 1;
	print_c_aux(params, len, c, count);
}

void	print_c_aux(t_struct *params, int len, char c, t_count *count)
{
	if (!params->minus && params->width >= 0 && !params->zero)
		ft_width(params, len, count);
	ft_zero(params, len, count);
	ft_putchar_fd(c, 1);
	if (params->minus || params->width < 0)
		ft_width(params, len, count);
	count->ret++;
}
