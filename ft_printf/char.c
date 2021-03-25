#include "libft/libft.h"
#include "ft_printf.h"

void	print_c(va_list ap, t_struct *params)
{
	ft_c_aux(params);
	ft_putchar_fd(va_arg(ap, int), 1); 
}

void	ft_c_aux(t_struct *params)
{
	int width;

	width = params->width - 1;
	if (params->zero)
	{
		while (width-- > 0)
			ft_putchar_fd(' ', 1);
	}
	while (width-- > 0)
		ft_putchar_fd('0', 1);
}