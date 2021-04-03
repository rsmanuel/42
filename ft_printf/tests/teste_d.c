#include "../libft/libft.h"
#include "../ft_printf.h"

int main(void)
{
    /*
    printf("Tester (tests with multiple %%d)\n");
    printf("\n");
    ft_printf("[ %-3.2d ", 1);
    ft_printf("%10.42d ]", -1);
    printf("\n[ %-3.2d %10.42d ]", 1, -1);
    printf("\n");
    ft_printf("[ %-3.2d ", 10);
    ft_printf("%10.42d ]", -10);
    printf("\n[ %-3.2d %10.42d ]", 10, -10);
    printf ("\n");
    ft_printf("[ *%-4.5d* ", 10);
    ft_printf("*%10.21d* ]", -10);
    printf("\n[ *%-*.*d* *%*.*d* ]", 4, 5, 10, 10, 21, -10);
    printf("\n");
    ft_printf("[ *%-6.2d* ", 102);
    ft_printf("*%10.21d* ]", -101);
    printf("\n[ *%-*.*d* *%*.*d* ]",  6, 2, 102, 10, 21, -101);
    printf("\n");
    ft_printf("[ *%-6.2d* ", 102);
    ft_printf("*%10.21d* ]", 101);
    printf("\n[ *%*.*d* *%*.*d* ]", -6, 2, 102, 10, 21, 101);
    printf("\n");
    ft_printf("[ 0*%0-6.2d*0 ", 102);
    ft_printf("0*%010.21d*0 ]", -101);
    printf("\n[ 0*%0-*.*d*0 0*%0*.*d*0 ]", 6, 2, 102, 10, 21, -101);
    printf("\n");
    ft_printf("[ %50.10d ]", 12345);
    printf("\n[ %50.10d ]", 12345);
    printf("\n<%010d>\n", -100);
    ft_printf("<%010d>", -100);
    printf("\nret: %d", ft_printf("%5.d", -2));
    printf("\n");
    printf("\nret: %d", printf("%5.d", -2));
    */
    printf("\nret: %d", ft_printf("[ 0*%021.10d*0 ]", -101));
    printf("\n");
    printf("\nret: %d", printf("[ 0*%021.10d*0 ]", -101));
}