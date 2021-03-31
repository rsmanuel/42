#include "../libft/libft.h"
#include "../ft_printf.h"

int main(void)
{
    //printf(" 0*%0-*.*d*0 0*%0*.*d*0 \n", 2, 6, 102, 21, 10, -101);
    //printf("\n<%d>\n", ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 2, 6, 102, 21, 10, -101));
    printf("[%.*d]\n", 10, 125); 
    ft_printf("[%.*d]", 10, 125);
}