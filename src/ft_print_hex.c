#include "../ft_printf.h"

char	*ft_convert_hex(unsigned int n, int *num_len, int x)
{
	char	*num_start;
	char	*num;
	unsigned int	num_rank;
	unsigned int	tmp;

	num_rank = 1;
	while (n / num_rank / HEX != 0 && ++*num_len)
		num_rank *= HEX;
	num = malloc(sizeof(char) * (*num_len + 1));
	num_start = num;
	while (num_rank != 0)
	{
		tmp = n / num_rank;
		if (tmp > 9)
			*num = (char)(tmp + x - 33);
		else
			*num = (char)(tmp + 48);
		n %= num_rank;
		num_rank /= HEX;
		++num;
	}
	*num = '\0';
	return (num_start);
}

void	ft_format_hex(char *str, t_form *f_flag, int i)
{
	if (f_flag->minus == 0)
	{
		ft_memset(' ', f_flag->width);
		ft_putnchar("0x", f_flag->sharp);
		ft_memset('0', f_flag->precision);
		ft_putnchar(str, i);
	}
	else
	{
		ft_putnchar("0x", f_flag->sharp);
		ft_memset('0', f_flag->precision);
		ft_putnchar(str, i);
		ft_memset(' ', f_flag->width);
	}
}

void	ft_print_logic_hex(t_form *f_flag, int n_len, int *size)
{
	if (f_flag->width > f_flag->precision && f_flag->precision > n_len)
	{
		f_flag->width -= (f_flag->precision + f_flag->sharp);
		f_flag->precision -= n_len;
	}
	else if (f_flag->precision >= f_flag->width && f_flag->precision >= n_len)
	{
		f_flag->width = 0;
		f_flag->precision -= n_len;
	}
	else if (n_len >= f_flag->width && n_len > f_flag->precision)
	{
		f_flag->width = 0;
		f_flag->precision = 0;
	}
	else if (f_flag->width > n_len && n_len >= f_flag->precision)
	{
		f_flag->width -= (n_len + f_flag->sharp);
		f_flag->precision = 0;
	}
	*size += f_flag->width + f_flag->precision + f_flag->sharp + n_len;
}

void	ft_print_hex(unsigned int n, int x, t_form *f_flag, int *size)
{
	char	*num;
	int		n_len;

	num = NULL;
	n_len = 1;
	num = ft_convert_hex(n, &n_len, x);
	ft_print_logic_hex(f_flag, n_len, size);
	ft_format_hex(num, f_flag, n_len);
	free(num);
}
