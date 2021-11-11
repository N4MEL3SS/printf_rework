int	ft_isflag(char flag)
{
	if (flag == '-' || flag == '+' || flag == '0'
		|| flag == ' ' || flag == '#')
		return (1);
	return (0);
}
