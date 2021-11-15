#include "../ft_printf.h"

void	ft_init_format(t_form *f_flag)
{
	f_flag->minus = 0;
	f_flag->plus = 0;
	f_flag->zero = 0;
	f_flag->space = 0;
	f_flag->sharp = 0;
	f_flag->width = 0;
	f_flag->precision = 0;
	f_flag->dot = 0;
}

const char	*ft_pars_flag(const char *f_str, t_form *f_flag)
{
	while (ft_isflag(*f_str))
	{
		if (!f_flag->minus && *f_str == '-')
			f_flag->minus = 1;
		else if (!f_flag->zero && *f_str == '0')
			f_flag->zero = 1;
		else if (!f_flag->plus && *f_str == '+')
			f_flag->plus = 1;
		else if (!f_flag->space && *f_str == ' ')
			f_flag->space = 1;
		else if (!f_flag->sharp && *f_str == '#')
			f_flag->sharp = 2;
		f_str++;
	}
	return (f_str);
}

const char	*ft_pars_width(const char *f_str, va_list ap, t_form *f_flag)
{
	int		result;

	if (*f_str == '*')
	{
		++f_str;
		result = va_arg(ap, int);
		if (result < 0)
		{
			f_flag->minus = 1;
			result *= -1;
		}
	}
	else
	{
		result = 0;
		while (ft_isdigit(*f_str))
		{
			result = result * 10 + (int)(*f_str - 48);
			++f_str;
		}
	}
	f_flag->width = result;
	return (f_str);
}

const char	*ft_pars_precision(const char *f_str, va_list ap, t_form *f_flag)
{
	int		result;

	f_flag->dot = 1;
	if (*f_str == '*')
	{
		++f_str;
		result = va_arg(ap, int);
		if (result < 0)
			result = 0;
	}
	else
	{
		result = 0;
		while (ft_isdigit(*f_str))
		{
			result = result * 10 + (int)(*f_str - 48);
			++f_str;
		}
	}
	f_flag->precision = result;
	return (f_str);
}

const char	*ft_pars(const char *f_str, va_list ap, t_form *f_flag)
{
	ft_init_format(f_flag);
	f_str = ft_pars_flag(++f_str, f_flag);
	if (ft_isdigit(*f_str) || *f_str == '*')
		f_str = ft_pars_width(f_str, ap, f_flag);
	if (*f_str == '.')
		f_str = ft_pars_precision(++f_str, ap, f_flag);
	if (f_flag->zero == 1 && f_flag->minus == 1)
		f_flag->zero = 0;
	if (f_flag->space == 1 && f_flag->plus == 1)
		f_flag->space = 0;
	return (f_str);
}
