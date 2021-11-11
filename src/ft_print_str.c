#include "../ft_printf.h"

void	ft_print_str(char *str, t_format f_flag)
{
	int	len;

//	if (!str)
//		ft_putnchar("(null)", 6);
	len = ft_strlen(str);
	if (f_flag.precision != 0 && f_flag.precision < len)
		len = f_flag.precision;
	if (f_flag.width > len)
		f_flag.width -= len;
	if (f_flag.minus == 0)
	{
		ft_memset(' ', f_flag.width);
		ft_putnchar(str, len);
	}
	else
	{
		ft_putnchar(str, len);
		ft_memset(' ', f_flag.width);
	}
}
