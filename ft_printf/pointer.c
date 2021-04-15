#include "libft/libft.h"
#include "ft_printf.h"

void	print_p(va_list ap, t_struct *params)
{
	void	*ptr;

	ptr = va_arg(ap, void *);
	params->ptr = ptr;
	ft_putstr_fd("0x", 1);
}
