#include "ft_printf.h"

int	main(void)
{
	int		i;
	char	*c;

	c = NULL;
	printf("ft:\n");
	i = ft_printf("this %d number", 17);
	printf("%i\n", i);
	printf("or:\n");
	i = printf("this %d number", 17);
	printf("%i\n", i);
	return (0);
}
