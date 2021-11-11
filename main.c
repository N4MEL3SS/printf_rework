#include "ft_printf.h"

int	main(void)
{
	char	str[] = "DEUS VOlT AVE MARIO COMICS-SANS EX";
	int		i;

	i = INT32_MAX;
	ft_printf("1. %s;\n", str);
	printf("1. %s;\n", str);
	ft_printf("2. %50s;\n", str);
	printf("2. %50s;\n", str);
	ft_printf("3. %-50s;\n", str);
	printf("3. %-50s;\n", str);
	ft_printf("4. %-50.4s;\n", str);
	printf("4. %-50.4s;\n", str);
	ft_printf("5. %*.*s;\n", 50, 4, str);
	printf("5. %*.*s;\n", 50, 4, str);
	ft_printf("6. %*.*s;\n%20p;\n", 50, 4, str, &i);
	printf("6. %*.*s;\n%20p;\n", 50, 4, str, &i);
	//ft_printf("%20.10p;\nSimple Text;\n%20.10p\n", &i, &i);
	//printf("%20p;\n", &i);
	return (0);
}
