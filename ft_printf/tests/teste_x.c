#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
	ft_printf("[ 0*%021.10u*0 ]", -101);
	printf("\n[ 0*%021.10u*0 ]", -101);
}
