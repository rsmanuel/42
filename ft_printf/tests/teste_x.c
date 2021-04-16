#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
	char a;
	char *ptr;

	a = 'a';
	ptr = &a;
	ft_printf("[ %p ]", ptr);
	printf("\n[ %p ]", ptr);
}
