#include "libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list ap, t_struct *params)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	len = ft_strlen(str);
	params->str = str;
	print_s_aux(params, len, str);
}

void	print_s_aux(t_struct *params, int len, char *str)
{
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len);
	ft_zero(params, len);
	if (!params->precision)
		ft_putstr_fd(str, 1);
	if (params->precision)
		ft_precision(params, len, str);
	if (params->minus)
		ft_width(params, len);
}
