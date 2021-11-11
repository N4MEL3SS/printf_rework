#include "../ft_printf.h"

char	*ft_convert_ptr(char *num, size_t n, short *num_len)
{
	size_t	num_rank;
	size_t	tmp;
	char	*num_p;

	num_rank = 1;
	while (n / num_rank / HEX != 0 && ++*num_len)
		num_rank *= HEX;
	num = malloc(sizeof(char) * (*num_len + 1));
	num_p = num;
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
		num_rank /= 16;
		++num;
	}
	*num = '\0';
	return (num_p);
}

void	ft_format_ptr(char *str, t_format f_flag, int len)
{
	if (f_flag.minus == 0)
	{
		ft_memset(' ', f_flag.width - len);
		ft_putnchar(str, len);
	}
	else
	{
		ft_putnchar(str, len);
		ft_memset(' ', f_flag.width - len);
	}
}

void	ft_print_ptr(size_t n, t_format f_flag)
{
	char	*num;
	short	num_len;

	num = NULL;
	num_len = 3;
	num = ft_convert_ptr(num, n, &num_len);
	ft_format_ptr(num, f_flag, num_len);
	free(num);
}
