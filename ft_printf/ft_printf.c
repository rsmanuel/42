#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

void debug_params(t_struct *params)
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
}

void	print_c(va_list ap)
{
	ft_putchar_fd(va_arg(ap, int), 1); 
}

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

int main(void)
{
	printf("------------------------------------------------------------\n");
	printf("\t\tJUST %%d\n");
	printf("------------------------------------------------------------\n");

	/* JUST %d */
	ft_printf("ft_printf:\t[%d]\n", 0);
	printf("printf:\t\t[%d]\n", 0);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d]\n", -7);
	printf("printf:\t\t[%d]\n", -7);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d]\n", 1560133635);
	printf("printf:\t\t[%d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d]\n", -2035065302);
	printf("printf:\t\t[%d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d WIDTH\n");
	printf("------------------------------------------------------------\n");

	/* %d WIDTH */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%5d]\n", 0);
	printf("printf:\t\t[%5d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%10d]\n", -7);
	printf("printf:\t\t[%10d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%40d]\n", 1560133635);
	printf("printf:\t\t[%40d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%0d]\n", -2035065302);
	printf("printf:\t\t[%0d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d MINUS and WIDTH\n");
	printf("------------------------------------------------------------\n");

	/* %d MINUS and WIDTH */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%-5d]\n", 0);
	printf("printf:\t\t[%-5d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%-10d]\n", -7);
	printf("printf:\t\t[%-10d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%-40d]\n", 1560133635);
	printf("printf:\t\t[%-40d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%-d]\n", -2035065302);
	printf("printf:\t\t[%-d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d ZERO-FILL\n");
	printf("------------------------------------------------------------\n");

	/* %d ZERO-FILL */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%05d]\n", 0);
	printf("printf:\t\t[%05d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%010d]\n", -7);
	printf("printf:\t\t[%010d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%040d]\n", 1560133635);
	printf("printf:\t\t[%040d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%00d]\n", -2035065302);
	printf("printf:\t\t[%00d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d PLUS SIGN\n");
	printf("------------------------------------------------------------\n");

	/* %d PLUS SIGN */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%+5d]\n", 0);
	printf("printf:\t\t[%+5d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%+10d]\n", -7);
	printf("printf:\t\t[%+10d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%+40d]\n", 1560133635);
	printf("printf:\t\t[%+40d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%+0d]\n", -2035065302);
	printf("printf:\t\t[%+0d]\n", -2035065302);
}