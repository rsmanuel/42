#include "../libft/libft.h"
#include "../ft_printf.h"

int main(void)
{
    printf("[%050.10s]\n", "this is a string");
    ft_printf("[%050.10s]", "this is a string");
}