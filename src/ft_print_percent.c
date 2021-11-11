#include "../ft_printf.h"

void	ft_print_percent(t_format f_flag)
{
	if (f_flag.minus == 0)
	{
		if (f_flag.zero == 1)
			ft_memset('0', f_flag.width - 1);
		else
			ft_memset(' ', f_flag.width - 1);
		ft_putnchar("%", 1);
	}
	else
	{
		ft_putnchar("%", 1);
		ft_memset(' ', f_flag.width - 1);
	}
}
