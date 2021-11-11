#include "../ft_printf.h"

void	ft_putnchar(char *str, size_t i)
{
	write(1, str, i);
}
