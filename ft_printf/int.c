#include "libft/libft.h"
#include "ft_printf.h"

void	print_d_aux(t_struct *params)
{
	char	*str;

	str = params->str;
	if (!params->precision && str[0] == '0')
		return ;
	ft_putstr_fd(str, 1);
	params->ret += ft_strlen(str);
}

void	print_d(va_list ap, t_struct *params)
{
	int		nb;
	char	*str;
	int		len;

	nb = va_arg(ap, int);
	str = ft_itoa(nb);
	if (nb < 0)
	{
		free(str);
		str = ft_itoa(-nb);
		ft_putchar_fd('-', 1);
	}
	params->str = str;
	params->number = nb;
	print_d_aux(params);
	free(str);
}
