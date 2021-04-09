#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
	ft_printf("[ %10.s ", "123");
	ft_printf("%.1s ]", "4567");
	printf("\n[ %*.s %.1s ]", 10, "123", "4567");
}
