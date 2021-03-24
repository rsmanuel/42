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
	if (params->plus && nb >= 0)
		len++;
	print_d_aux(params, len, nb, str);
}

void	print_d_aux(t_struct *params, int len, int nb, char *str)
{
	if(params->minus && params->width && params->plus)
		ft_putchar_fd('+', 1);
	if (params->width && !params->minus)
		print_width_and_zero_d(params, len, nb);
	ft_putstr_fd(str, 1);
	if (params->width && params->minus)
		print_width_and_zero_d(params, len, nb);
}

void print_width_and_zero_d(t_struct *params, int len, int nb)
{
	int width;
	
	width = (params->width) - len;
	if (params->zero && (!params->minus || params->str[0] == '-'))
	{
		if (params->plus && params->zero && nb >= 0)
			ft_putchar_fd('+', 1);
		while (width-- > 0)
			ft_putchar_fd('0', 1);
	}
	while (width-- > 0)
		ft_putchar_fd(' ', 1);
	if (params->plus && params->width && !params->zero && nb >= 0)
		ft_putchar_fd('+', 1); 
}