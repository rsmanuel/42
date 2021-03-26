#include "libft/libft.h"
#include "ft_printf.h"

void	print_d(va_list ap, t_struct *params)
{
	int		nb;
	char	*str;
	int		len;

	nb = va_arg(ap, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if ((params->minus || params->zero) && nb < 0)
	{
		str = ft_itoa(-nb);
		ft_putchar_fd('-', 1);
	}
	params->str = str;
	if ((params->plus || params->space) && nb >= 0)
		len++;
	print_d_aux(params, len, nb, str);
}

void	print_d_aux(t_struct *params, int len, int nb, char *str)
{
	if (params->space && nb >= 0)
		ft_putchar_fd(' ', 1);
	if (!params->minus)
		ft_width(params, len);
	if (params->plus && nb >= 0)
			ft_putchar_fd('+', 1);
	ft_zero(params, len);
	ft_putstr_fd(str, 1);
	if (params->minus)
		ft_width(params, len);
}