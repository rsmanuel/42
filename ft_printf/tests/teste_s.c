#include "../libft/libft.h"
#include "../ft_printf.h"

int main(void)
{
    printf("%.s\n", "ola");
    printf("\n<%d>\n", ft_printf("%.s", "ola"));
}