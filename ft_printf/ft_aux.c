#include "libft/libft.h"
#include "ft_printf.h"

void	ft_width(t_struct *params, int len)
{
	int i;
	
	i = len;
	while (i-- > 0)
	{
		ft_putchar_fd(' ', 1);
		params->ret++;
	}
}

void	ft_zero(t_struct *params, int len)
{
	int	i;

	i = len;
	while (i-- > 0)
	{
		ft_putchar_fd('0', 1);
		params->ret++;
	}
}

/*
**void	ft_precision(t_struct *params)
**{
**	int		i;
**	char 	*str;
**
**	i = 0;
**	str = params->str;
**	while (str && str[i] != '\0' && i < params->precision)
**	{
**		ft_putchar_fd(str[i], 1);
**		params->ret++;
**		i++;
**	}
**}
*/
