#include "ft_printf.h"

const char	*ft_print_type(const char *f_str, va_list ap)
{
	t_format	f_flag;

	f_str++;
	f_str = ft_parser(f_str, ap, &f_flag);
	if (f_flag.type == 's')
		ft_print_str(va_arg(ap, char *), f_flag);
	else if (f_flag.type == 'i' || f_flag.type == 'd')
		ft_print_int(va_arg(ap, int), f_flag);
	else if (f_flag.type == 'p')
		ft_print_ptr((size_t)va_arg(ap, void *), f_flag);
	else if (f_flag.type == 'x' || f_flag.type == 'X')
		ft_print_hex(va_arg(ap, int), f_flag);
	else if (f_flag.type == 'u')
		ft_print_int((unsigned int)va_arg(ap, int), f_flag);
	else if (f_flag.type == 'c')
		ft_print_char(va_arg(ap, int), f_flag);
	else if (f_flag.type == '%')
		ft_print_percent(f_flag);
	f_str++;
	return (f_str);
}

const char	*ft_print_buff(const char *f_str)
{
	size_t		len;
	char		*tmp;

	len = 0;
	tmp = (char *)f_str;
	while (*(f_str) && *(f_str) != '%' && ++f_str)
		len++;
	ft_putnchar(tmp, len);
	return (f_str);
}

void	ft_printf(const char *f_str, ...)
{
	va_list	ap;

	va_start(ap, f_str);
	while (*f_str)
	{
		if (*f_str && *f_str != '%')
			f_str = ft_print_buff(f_str);
		else
			f_str = ft_print_type(f_str, ap);
	}
	va_end(ap);
}
