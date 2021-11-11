#include "../ft_printf.h"

void	ft_memset(int c, long n)
{
	long	i;
	char	*dst;

	if (n > 0)
	{
		i = -1;
		dst = malloc(sizeof(char) * n);
		while (++i < n)
			dst[i] = (char)c;
		ft_putnchar(dst, n);
		free(dst);
	}
}
