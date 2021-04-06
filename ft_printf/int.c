#include "libft/libft.h"
#include "ft_printf.h"

/*void	print_d_aux(t_struct *params, int len)
{
}*/

void	print_d(va_list ap, t_struct *params)
{
	int		nb;
	char	*str;
	int		len;

	nb = va_arg(ap, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	if (nb < 0)
	{
		free(str);
		str = ft_itoa(-nb);
		ft_putchar_fd('-', 1);
	}
	params->str = str;
	params->number = nb;
	if ((params->plus || params->space) && nb >= 0)
		len++;
	//print_d_aux(params, len);
	free(str);
}
