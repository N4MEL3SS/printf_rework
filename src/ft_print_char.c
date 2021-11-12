#include "../ft_printf.h"

void	ft_print_char(char c, t_form *f_flag, int *size)
{
	if (f_flag->width > 2)
	{
		if (f_flag->minus == 0)
		{
			ft_memset(' ', f_flag->width - 1);
			ft_putnchar(&c, 1);
		}
		else
		{
			ft_putnchar(&c, 1);
			ft_memset(' ', f_flag->width - 1);
		}
	}
	else
	{
		f_flag->width = 1;
		ft_putnchar(&c, 1);
	}
	*size += f_flag->width;
}
