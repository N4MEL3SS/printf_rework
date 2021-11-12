#include "../ft_printf.h"

char	*ft_convert_ptr(size_t n, int *num_len)
{
	char	*num_start;
	char	*num;
	size_t	num_rank;
	size_t	tmp;

	num_rank = 1;
	while (n / num_rank / HEX != 0 && ++*num_len)
		num_rank *= HEX;
	num = malloc(sizeof(char) * (*num_len + 1));
	num_start = num;
	*(num++) = '0';
	*(num++) = 'x';
	while (num_rank != 0)
	{
		tmp = n / num_rank;
		if (tmp > 9)
			*num = (char)(tmp + 87);
		else
			*num = (char)(tmp + 48);
		n %= num_rank;
		num_rank /= HEX;
		++num;
	}
	*num = '\0';
	return (num_start);
}

void	ft_format_ptr(char *str, t_form *f_flag, int len)
{
	if (f_flag->minus == 0)
	{
		ft_memset(' ', f_flag->width);
		ft_putnchar(str, len);
	}
	else
	{
		ft_putnchar(str, len);
		ft_memset(' ', f_flag->width);
	}
}

void	ft_print_ptr(size_t n, t_form *f_flag, int *size)
{
	char	*num;
	int		num_len;

	num_len = 3;
	num = ft_convert_ptr(n, &num_len);
	if (f_flag->width > num_len)
		f_flag->width -= num_len;
	else
		f_flag->width = 0;
	*size += f_flag->width + num_len;
	ft_format_ptr(num, f_flag, num_len);
	free(num);
}
