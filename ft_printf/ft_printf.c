#include "libft/libft.h"
#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int			i;
	va_list		ap;
	t_struct	*params;
	t_count		*count;
	int			ret;

	i = 0;
	va_start(ap, fmt);
	params = (t_struct *)malloc(sizeof(t_struct));
	count = (t_count *)malloc(sizeof(t_count));
	reset_struct(params);
	if (!params || !count)
		return (0);
	count->ret = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			i += parse_str(&fmt[i + 1], ap, params, count);
		else
		{
			ft_putchar_fd(fmt[i], 1);
			count->ret++;
		}
		i++;
	}
	ret = count->ret;
	va_end(ap);
	free(count);
	free(params);
	return (ret);
	}
