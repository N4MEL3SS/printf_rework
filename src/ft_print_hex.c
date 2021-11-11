#include "../ft_printf.h"

void	ft_convert_hex(unsigned int n, char *num, short *num_len, int x)
{
	unsigned int	num_rank;
	unsigned int	tmp;

	num_rank = 1;
	while (n / num_rank / HEX != 0 && ++*num_len)
		num_rank *= HEX;
	num = malloc(sizeof(char) * (*num_len + 1));
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
}

void	ft_format_hex(char *str, t_format f_flag, size_t i)
{
	if (f_flag.minus == 0)
	{
		ft_memset(' ', f_flag.width - i);
		ft_putnchar(str, i);
	}
	else
	{
		ft_putnchar(str, i);
		ft_memset(' ', f_flag.width - i);
	}
}

void	ft_print_hex(long n, t_format f_flag)
{
	char	*num;
	short	num_len;

	num = NULL;
	num_len = 1;
	ft_convert_hex(n, num, &num_len, f_flag.type);
	ft_format_hex(num, f_flag, num_len);
	free(num);
}
