#include "libft/libft.h"
#include "ft_printf.h"

void print(va_list ap, t_struct *params)
{
	if (params->conversion == 'c')
		print_c(ap);
	else if (params->conversion == 's')
		print_s(ap);
	else if (params->conversion == 'd')
		print_d(ap, params);
}