#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#define CONVERSION "cspdiuxXnfge"
#define FLAG "-+ 0#"
#define	PRECISION ".0123456789*"

#include <stdarg.h>
#include <unistd.h>

typedef struct	s_struct
{
	int	minus;
	int	plus;
	int	zero;
	int	space;
	int	hash;
	int width;
	int precision;
}				t_struct;

int		ft_printf(const char *fmt, ...);
void	reset_struct(t_struct *params);

#endif