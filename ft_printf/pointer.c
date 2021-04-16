#include "libft/libft.h"
#include "ft_printf.h"

void	print_p(va_list ap, t_struct *params)
{
	unsigned long ptr;
	char *str;

	ptr = (unsigned long)va_arg(ap, void*);
	str = ft_itox(ptr, params);
	params->len = ft_strlen(str) + 2;
	if (!params->minus && params->width && !params->zero)
			ft_width(params, (params->width - params->len));
		if (params->zero && params->width && !params->minus)
			ft_zero(params, (params->width - params->len));
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		params->ret += (params->len);
		if (params->minus)
			ft_width(params, (params->width - params->len));
	free(str);
}
