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

void	ft_precision(t_struct *params, int len, char *str, t_count *count)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	c = 0;
	if (params->width && !params->zero)
		c = ' ';
	else if (params->width && params->zero)
		c = '0';
	while (c && i < len - params->precision)
	{
		ft_putchar_fd(c, 1);
		count->ret++;
		i++;
	}
	while (str && str[j] != '\0' && j < params->precision)
	{
		ft_putchar_fd(str[j], 1);
		count->ret++;
		j++;
	}
}
