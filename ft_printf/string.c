#include "libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list ap, t_struct *params, t_count *count)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	params->str = str;
	print_s_aux(params, len, str, count);
}

void	print_s_aux(t_struct *params, int len, char *str, t_count *count)
{
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len, count);
	ft_zero(params, len, count);
	if (!params->precision)
		ft_putstr_fd(str, 1);
	if (params->precision)
		ft_precision(params, len, str, count);
	if (params->minus)
		ft_width(params, len, count);
	count->ret++;
}
