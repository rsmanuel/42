#include "libft/libft.h"
#include "ft_printf.h"

void	print_u_aux(t_struct *params)
{
	char	*str;

	str = params->str;
	if (params->precision > -1)
		treat_precision(params);
	else
	{
		if (!params->minus && params->width && !params->zero)
			ft_width(params, (params->width - params->len));
		if (params->zero && params->width && !params->minus)
			ft_zero(params, (params->width - params->len));
		ft_putstr_fd(str, 1);
		params->ret += ft_strlen(str);
		if (params->minus)
			ft_width(params, (params->width - params->len));
	}
}

void	print_u(va_list ap, t_struct *params)
{
	unsigned int		nb;
	char				*str;

	nb = va_arg(ap, unsigned int);
	str = ft_itoa_u(nb);
	params->len = ft_strlen(str);
	if (!params->precision && str[0] == '0')
		params->len = 0;
	params->str = str;
	print_u_aux(params);
	free(str);
}
