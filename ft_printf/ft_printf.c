#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int			i;
	va_list		ap;
	t_struct	*params;
	int			ret;

	i = 0;
	va_start(ap, fmt);
	params = (t_struct *)malloc(sizeof(t_struct));
	reset_struct(params);
	if (!params)
		return (0);
	params->ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%' && fmt[i + 1] != '%')
			i += parse_str(&fmt[i + 1], ap, params);
		else
		{
			ft_putchar_fd(fmt[i], 1);
			params->ret++;
		}
		i++;
	}
	ret = params->ret;
	va_end(ap);
	free(params);
	return (ret);
	}
