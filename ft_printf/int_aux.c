#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len, int nb)
{
	int width;

	width = params->width - len;
	if (params->width && !params->minus && !params->zero)
	{
		while(width-- > 0)
			ft_putchar_fd(' ', 1);
		ft_plus(params, nb);
	}
}

void	ft_minus(t_struct *params, int len, int nb)
{
	int width;

	width = params->width - len;
	if(params->width && params->minus)
	{
		while(width-- > 0)
			ft_putchar_fd(' ', 1);
	}
}

void	ft_zero(t_struct *params, int len, int nb)
{
	int width;

	width = params->width - len;
	if (params->zero && params->width && !params->minus)
	{
		ft_plus(params, nb);
		while(width-- > 0)
			ft_putchar_fd('0', 1);
	}

}

void	ft_plus(t_struct *params, int nb)
{
	if (params->plus && nb >= 0)
			ft_putchar_fd('+', 1);
}

void	ft_space(t_struct *params, int nb)
{
	if (params->space && nb >= 0)
		ft_putchar_fd(' ', 1);
}