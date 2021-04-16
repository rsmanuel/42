#include "libft/libft.h"
#include "ft_printf.h"

void	print_p(va_list ap, t_struct *params)
{
	unsigned long	ptr;
	char *str;

	ptr = (unsigned long)va_arg(ap, void*);
	params->ptr = ptr;
	str = ft_itox(params->ptr, params);
	ft_putstr_fd(str, 1);
}
