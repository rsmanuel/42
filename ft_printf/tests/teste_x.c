#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
	printf("%d", ft_printf("[ %% ]", UINT_MAX));
	printf("\n[ %9.1x ]", UINT_MAX);
}
