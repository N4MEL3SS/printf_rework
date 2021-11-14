#include "ft_printf.h"

int	main(void)
{
	int				i;
	//unsigned int	t;

	//t = INT32_MAX;
	i = ft_printf("ft NULL %s NULL \n", NULL);
	printf("%i\n", i);
	i = printf("pt NULL %s NULL \n", NULL);
	printf("%i\n", i);

//	i = ft_printf("%*.*s;Simple Text;%10.5s;\n", -10, 5,
//			"Test1 str print", "Test2 str print");
//	printf("%i\n", i);
//	i = printf("%*.*s;Simple Text;%10.5s;\n", -10, 5,
//			"Test1 str print", "Test2 str print");
//	printf("%i\n", i);
//
//	i = ft_printf("%010%;%-10%;\n");
//	printf("%i\n", i);
//	i = printf("%010%;%-10%;\n");
//	printf("%i\n", i);
//
//	i = ft_printf("%-20p;\n", &t);
//	printf("%i\n", i);
//	i = printf("%-20p;\n", &t);
//	printf("%i\n", i);
//	i = ft_printf("%20p;\n", &t);
//	printf("%i\n", i);
//	i = printf("%20p;\n", &t);
//	printf("%i\n", i);
//
//	i = ft_printf("%#5.7x;\n", t);
//	printf("%i\n", i);
//	i = printf("%#5.7x;\n", t);
//	printf("%i\n", i);
//	i = ft_printf("%-#20.8x;\n", t);
//	printf("%i\n", i);
//	i = printf("%-#20.8x;\n", t);
//	printf("%i\n", i);
//
//	i = ft_printf("%- 15.20i;\n", t);
//	printf("%i\n", i);
//	i = printf("%- 15.20i;\n", t);
//	printf("%i\n", i);
	return (0);
}
