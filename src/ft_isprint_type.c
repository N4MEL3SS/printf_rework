int	ft_isprintf_type(int c)
{
	if (c == 'c' || c == 's' || c == 'i' || c == 'd' || c == 'u'
		|| c == 'p' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}
