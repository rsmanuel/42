#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_struct
{
	char	conversion;
	char	*str;
	int		minus;
	int		plus;
	int		zero;
	int		space;
	int		hash;
	int		width;
	int		precision;
}				t_struct;

typedef	struct s_count
{
	int		ret;
}			t_count;


int		ft_printf(const char *fmt, ...);
void	reset_struct(t_struct *params);
void	debug_params(t_struct *params);
void	print(va_list ap, t_struct *params, t_count *count);
void	print_c(va_list ap, t_struct *params, t_count *count);
void	print_s(va_list ap, t_struct *params, t_count *count);
void	print_d(va_list ap, t_struct *params, t_count *count);
void	parse_flags(const char *str, t_struct *params);
void	parse_precision(const char *str, va_list ap, t_struct *params);
void	parse_width(const char *str, va_list ap, t_struct *params);
int		parse_str(const char *str, va_list ap, t_struct *params, t_count *count);
void	print_plus(t_struct *params, int nb, int len);
void	print_d_aux(t_struct *params, int len, int nb, char *str, t_count *count);
void	print_c_aux(t_struct *params, int len, char c, t_count *count);
void	print_s_aux(t_struct *params, int len, char *str, t_count *count);
void	ft_width(t_struct *params, int len, t_count *count);
void	ft_zero(t_struct *params, int len, t_count *count);
void	ft_precision(t_struct *params, int len, char *str, t_count *count);

#endif
