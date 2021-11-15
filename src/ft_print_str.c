#include "../ft_printf.h"

void	ft_print_logic_str(t_form *f_flag, int *str_len, int *size)
{

	if (f_flag->dot != 0 && f_flag->precision < *str_len)
		*str_len = f_flag->precision;
	if (f_flag->width > *str_len)
		f_flag->width -= *str_len;
	else
		f_flag->width = 0;
	*size += f_flag->width + *str_len;
}

void	ft_print_str(char *str, t_form *f_flag, int *size)
{
	int	str_len;

	if (!str)
		str_len = 6;
	else
		str_len = ft_strlen(str);
	ft_print_logic_str(f_flag, &str_len, size);
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
	if (!str)
		ft_putnchar("(null)", 6);
}
