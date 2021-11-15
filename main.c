#include "ft_printf.h"

int	main(void)
{
	int		i;
	char	*c;

	c = NULL;
	printf("ft:\n");
	i = ft_printf("%32s\n", c);
	printf("%i\n", i);
	printf("or:\n");
	i = printf("%32s\n", c);
	printf("%i\n", i);
	return (0);
}
