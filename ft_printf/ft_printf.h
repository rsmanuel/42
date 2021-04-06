#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_struct
{
	char	conversion;
	char	*str;
	int		number;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		precision;
	int		ret;
}				t_struct;

int		ft_printf(const char *fmt, ...);
void	reset_struct(t_struct *params);
void	print(va_list ap, t_struct *params);
void	print_c(va_list ap, t_struct *params);
void	print_s(va_list ap, t_struct *params);
void	print_d(va_list ap, t_struct *params);
void	print_x(va_list ap, t_struct *params);
//void	parse_flags(const char *str, t_struct *params);
//void	parse_precision(const char *str, va_list ap, t_struct *params);
//void	parse_width(const char *str, va_list ap, t_struct *params);
int		parse_str(const char *str, va_list ap, t_struct *params);
void	ft_width(t_struct *params, int len);
void	ft_zero(t_struct *params, int len);
void	ft_precision(t_struct *params);

#endif
