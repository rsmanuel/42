#include "libft/libft.h"
#include "ft_printf.h"

void	print_s(va_list ap, t_struct *params, t_count *count)
{
	char	*str;
	char 	*dup;

	str = va_arg(ap, char *);
	dup = NULL;
	if (!str)
	{
		dup = ft_strdup("(null)");
		str = dup;
	}
	params->str = str;
	print_s_aux(params, str, count);
	if (dup)
		free(dup);	
}

void	print_s_aux(t_struct *params, char *str, t_count *count)
{
	char *sub;
	int len;
	
	sub = NULL;
	if (params->precision > -1)
	{	
		sub = ft_substr(str, 0, params->precision);
		str = sub;
	}
	len = ft_strlen(str);
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len, count);
	if (params->zero && params->width && !params->minus && !params->precision)
		ft_zero(params, len, count);
	if (params->precision > -1)
		ft_precision(params, str, count);
	else
	{
		ft_putstr_fd(str, 1);
		count->ret += ft_strlen(str);
	}
	if (params->minus)
		ft_width(params, len, count);
	if (sub)
		free(sub);
}
