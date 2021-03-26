#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*void debug_params(t_struct *params)
{
	printf("\n\n");
	printf("\tminus: \t\t%d\n", params->minus);
	printf("\tplus: \t\t%d\n", params->plus);
	printf("\tzero: \t\t%d\n", params->zero);
	printf("\tspace: \t\t%d\n", params->space);
	printf("\thash: \t\t%d\n", params->hash);
	printf("\twidth: \t\t%d\n", params->width);
	printf("\tprecision: \t%d\n", params->precision);
	printf("\n\n");
}*/

void	print_s(va_list ap)
{
	ft_putstr_fd(va_arg(ap, char *), 1);
}

int		ft_printf(const char *fmt, ...)
{
	int i;
	va_list ap;
	t_struct *params;
	
	i = 0;
	va_start(ap, fmt);
	params = (t_struct *)malloc(sizeof(t_struct));
	reset_struct(params);						
	if (!params)
		return (0);
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i += parse_str(&fmt[i + 1], ap, params); 
		else
			ft_putchar_fd(fmt[i], 1);
		i++;
	}
	va_end(ap);
	free(params);
	return (0);
}