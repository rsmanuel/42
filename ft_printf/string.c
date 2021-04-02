#include "libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list ap, t_struct *params, t_count *count)
{
	int		len;
	char	*str;

	str = va_arg(ap, char *);
	if (!str && params->precision != 0)
		str = ft_strdup("(null)");
	len = ft_strlen(str);
	params->str = str;
	print_s_aux(params, len, str, count);
	if (!str && params->precision != 0)
		free(str);	
}

void	print_s_aux(t_struct *params, int len, char *str, t_count *count)
{
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len, count);
	if (params->zero && params->width && !params->minus && !params->precision)
		ft_zero(params, len, count);
	if (params->precision > -1)
		ft_precision(params, len, str, count);
	else
	{
		ft_putstr_fd(str, 1);
		count->ret += ft_strlen(str);
	}
	if (params->minus)
		ft_width(params, len, count);
}
