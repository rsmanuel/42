#include "libft/libft.h"
#include "ft_printf.h"

int main(void)
{
	printf("------------------------------------------------------------\n");
	printf("\t\tJUST %%d\n");
	printf("------------------------------------------------------------\n");

	/* JUST %d */
	ft_printf("ft_printf:\t[%d]\n", 0);
	printf("printf:\t\t[%d]\n", 0);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d]\n", -7);
	printf("printf:\t\t[%d]\n", -7);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d]\n", 1560133635);
	printf("printf:\t\t[%d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d]\n", -2035065302);
	printf("printf:\t\t[%d]\n", -2035065302);

    printf("------------------------------------------------------------\n");
	printf("\t\tMULTIPLE %%d\n");
	printf("------------------------------------------------------------\n");

    /* MULTIPLE %d */
	ft_printf("ft_printf:\t[%d], [%d], [%d]\n", 0, -1, 2);
	printf("printf:\t\t[%d], [%d], [%d]\n", 0, -1, 2);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d], [%d], [%d]\n", -7, 55, -123);
	printf("printf:\t\t[%d], [%d], [%d]\n", -7, 55, -123);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d], [%d], [%d]\n", 1560133635, -1231, -1);
	printf("printf:\t\t[%d], [%d], [%d]\n", 1560133635, -1231, -1);
	printf("------------------------------------------------------------\n");
	ft_printf("ft_printf:\t[%d], [%d], [%d], [%d], [%d]\n", -2035065302, 12, 123, 123124, -555);
	printf("printf:\t\t[%d], [%d], [%d], [%d], [%d]\n", -2035065302, 12, 123, 123124, -555);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d WIDTH\n");
	printf("------------------------------------------------------------\n");

	/* %d WIDTH */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%5d]\n", 0);
	printf("printf:\t\t[%5d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%10d]\n", -7);
	printf("printf:\t\t[%10d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%40d]\n", 1560133635);
	printf("printf:\t\t[%40d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%0d]\n", -2035065302);
	printf("printf:\t\t[%0d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d MINUS and WIDTH\n");
	printf("------------------------------------------------------------\n");

	/* %d MINUS and WIDTH */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%-5d]\n", 0);
	printf("printf:\t\t[%-5d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%-10d]\n", -7);
	printf("printf:\t\t[%-10d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%-40d]\n", 1560133635);
	printf("printf:\t\t[%-40d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%-d]\n", -2035065302);
	printf("printf:\t\t[%-d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d ZERO-FILL\n");
	printf("------------------------------------------------------------\n");

	/* %d ZERO-FILL */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%05d]\n", 0);
	printf("printf:\t\t[%05d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%010d]\n", -7);
	printf("printf:\t\t[%010d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%040d]\n", 1560133635);
	printf("printf:\t\t[%040d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%00d]\n", -2035065302);
	printf("printf:\t\t[%00d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d PLUS SIGN\n");
	printf("------------------------------------------------------------\n");

	/* %d PLUS SIGN */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%+05d]\n", 0);
	printf("printf:\t\t[%+05d]\n", 0);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%+10d]\n", -7);
	printf("printf:\t\t[%+10d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%+40d]\n", 1560133635);
	printf("printf:\t\t[%+40d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%+0d]\n", -2035065302);
	printf("printf:\t\t[%+0d]\n", -2035065302);

	printf("------------------------------------------------------------\n");
	printf("\t\t%%d PLUS SIGN and ZERO-FILL\n");
	printf("------------------------------------------------------------\n");

	/* %d PLUS SIGN and ZERO-FILL */
	printf("width: 5\n");
	ft_printf("ft_printf:\t[%+05d]\n", 3);
	printf("printf:\t\t[%+05d]\n", 3);
	printf("------------------------------------------------------------\n");
	printf("width: 10\n");
	ft_printf("ft_printf:\t[%+010d]\n", -7);
	printf("printf:\t\t[%+010d]\n", -7);
	printf("------------------------------------------------------------\n");
	printf("width: 40\n");
	ft_printf("ft_printf:\t[%+040d]\n", 1560133635);
	printf("printf:\t\t[%+040d]\n", 1560133635);
	printf("------------------------------------------------------------\n");
	printf("width: 0\n");
	ft_printf("ft_printf:\t[%+00d]\n", -2035065302);
	printf("printf:\t\t[%+00d]\n", -2035065302);
}