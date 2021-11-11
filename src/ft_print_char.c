#include "../ft_printf.h"

void	ft_print_char(char c, t_format f_flag)
{
	if (f_flag.minus == 0)
	{
		ft_memset(' ', f_flag.width - 1);
		ft_putnchar(&c, 1);
	}
	else
	{
		ft_putnchar(&c, 1);
		ft_memset(' ', f_flag.width - 1);
	}
}
