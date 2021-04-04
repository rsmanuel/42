#include "libft/libft.h"
#include "ft_printf.h"

void	print(va_list ap, t_struct *params, t_count *count)
{
	if (params->conversion == 'c')
		print_c(ap, params, count);
	else if (params->conversion == 's')
		print_s(ap, params, count);
	else if (params->conversion == 'd' || params->conversion == 'i')
		print_d(ap, params, count);
	else if (params->conversion == 'x' || params->conversion == 'X')
		print_x(ap, params, count);
}
