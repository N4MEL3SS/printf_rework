#include "../ft_printf.h"

void	ft_convert_int(long n, char *num, short *num_len)
{
	unsigned int	num_rank;

	num_rank = 1;
	if (n < 0)
		ft_putnchar("-", 1);
	while (n / num_rank / DEC != 0 && ++*num_len)
		num_rank *= DEC;
	num = malloc(sizeof(char) * (*num_len + 1));
	while (num_rank != 0)
	{
		*num = (char)(n / num_rank + 48);
		n %= num_rank;
		num_rank /= DEC;
		++num;
	}
	*num = '\0';
}

void	ft_format_int(t_format f_flag, short num_len)
{
	if (f_flag.width > num_len)
		ft_memset(' ', f_flag.width - num_len);
	if (f_flag.plus)
		ft_putnchar("+", 1);
}

void	ft_print_int(long n, t_format f_flag)
{
	short	num_len;
	char	*num;

	num = NULL;
	num_len = 1;
	if (n < 0)
		ft_putnchar("-", 1);
	ft_convert_int(n, num, &num_len);
	ft_format_int(f_flag, num_len);
	ft_putnchar(num, num_len);
	free(num);
}
