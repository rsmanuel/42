#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len, t_count *count)
{
	int	width;

	width = params->width - len;
	{
		while (width-- > 0)
		{
			ft_putchar_fd(' ', 1);
			count->ret++;
		}
	}
}

void	ft_zero(t_struct *params, int len, t_count *count)
{
	int	width;

	width = params->width - len;
	while (width-- > 0)
	{
		ft_putchar_fd('0', 1);
		count->ret++;
	}
}

void	ft_precision(t_struct *params, char *str, t_count *count)
{
	int		i;

	i = 0;
	while (str && str[i] != '\0' && i < params->precision)
	{
		ft_putchar_fd(str[i], 1);
		count->ret++;
		i++;
	}
}
