#include "libft/libft.h"
#include "ft_printf.h"

void	print_s_aux(t_struct *params)
{
	char *sub;
	int len;
	
	sub = NULL;
	if (params->precision > -1)
	{	
		sub = ft_substr(params->str, 0, params->precision);
		params->str = sub;
	}
	len = ft_strlen(params->str);
	if (!params->minus && params->width && !params->zero)
		ft_width(params, len);
	if (params->zero && params->width && !params->minus && !params->precision)
		ft_zero(params, len);
	if (params->precision > -1)
		ft_precision(params);
	else
	{
		ft_putstr_fd(params->str, 1);
		params->ret += ft_strlen(params->str);
	}
	if (params->minus)
		ft_width(params, len);
	if (sub)
		free(sub);
}

void	print_s(va_list ap, t_struct *params)
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
	print_s_aux(params);
	if (dup)
		free(dup);	
}

