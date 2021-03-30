#include "../libft/libft.h"
#include "../ft_printf.h"

int main(void)
{
    //printf("[%50.20s]\n", "this is a string");
    ft_printf("[%50s]", "this is a string");
    sleep(10);
}