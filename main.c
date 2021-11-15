#include "ft_printf.h"

int	main(void)
{
	int	i;

	printf("ft:\n");
	i = ft_printf(" %04d ", -14);
	printf("%i\n", i);
	printf("or:\n");
	i = printf(" %04d ", -14);
	printf("%i\n", i);
	return (0);
}
