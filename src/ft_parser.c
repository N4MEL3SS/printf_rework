#include "../ft_printf.h"

void	ft_init_format(t_format *f_flag)
{
	(*f_flag).minus = 0;
	(*f_flag).minus = 0;
	(*f_flag).plus = 0;
	(*f_flag).zero = 0;
	(*f_flag).space = 0;
	(*f_flag).sharp = 0;
	(*f_flag).width = 0;
	(*f_flag).precision = 0;
	(*f_flag).type = 0;
}

const char	*ft_parser_flag(const char *f_str, t_format *f_flag)
{
	while (ft_isflag(*f_str))
	{
		if (!(*f_flag).minus && *f_str == '-')
			(*f_flag).minus = 1;
		else if (!(*f_flag).plus && *f_str == '+')
			(*f_flag).plus = 1;
		else if (!(*f_flag).zero && *f_str == '0')
			(*f_flag).zero = 1;
		else if (!(*f_flag).space && *f_str == ' ')
			(*f_flag).space = 1;
		else if (!(*f_flag).sharp && *f_str == '#')
			(*f_flag).sharp = 1;
		f_str++;
	}
	if ((*f_flag).zero == 1 && (*f_flag).minus == 1)
		(*f_flag).zero = 0;
	return (f_str);
}

const char	*ft_parser_wp(const char *f_str, va_list ap,
							t_format *f_flag, short i)
{
	long		result;

	result = 0;
	if (*f_str == '*')
	{
		result = va_arg(ap, int);
		if (result < 0)
			result = 0;
		++f_str;
	}
	else
	{
		while (ft_isdigit(*f_str))
		{
			result = result * 10 + (long)*f_str - 48;
			++f_str;
		}
	}
	if (i == 0)
		(*f_flag).width = (int)result;
	else if (i == 1)
		(*f_flag).precision = (int)result;
	return (f_str);
}

const char	*ft_parser(const char *f_str, va_list ap, t_format *f_flag)
{
	ft_init_format(f_flag);
	f_str = ft_parser_flag(f_str, f_flag);
	if (ft_isdigit(*f_str) || *f_str == '*')
		f_str = ft_parser_wp(f_str, ap, f_flag, 0);
	if (*f_str == '.')
		f_str = ft_parser_wp(++f_str, ap, f_flag, 1);
	if (ft_isprintf_type(*f_str))
		(*f_flag).type = *f_str;
	return (f_str);
}
