#include "../ft_printf.h"

void	ft_print_str(char *str, t_form *f_flag, int *size)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (f_flag->precision != 0 && f_flag->precision < str_len)
		str_len = f_flag->precision;
	if (f_flag->width > str_len)
		f_flag->width -= str_len;
	else
		f_flag->width = 0;
	if (f_flag->minus == 0)
	{
		ft_memset(' ', f_flag->width);
		ft_putnchar(str, str_len);
	}
	else
	{
		ft_putnchar(str, str_len);
		ft_memset(' ', f_flag->width);
	}
	*size += f_flag->width + str_len;
}
