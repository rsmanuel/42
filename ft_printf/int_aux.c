#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	if (params->width && !params->zero)
	{
		while(width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_zero(t_struct *params, int len)
{
	int width;

	width = params->width - len;
	if (params->zero && params->width && !params->minus)
	{
		while(width-- > 0)
			ft_putchar_fd('0', 1);
	}
}