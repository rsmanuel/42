#include "../libft/libft.h"
#include "../ft_printf.h"
#include <limits.h>

int main(void)
{
    ft_printf("[%09.0d]", UINT_MAX + 1);
    printf("\n[%09.0d]", UINT_MAX + 1);
}