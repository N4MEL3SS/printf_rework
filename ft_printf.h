#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h> //TODO: Удалить
# include <unistd.h>

# define DEC 10
# define HEX 16

typedef struct s_format
{
	short		minus;
	short		plus;
	short		zero;
	short		space;
	short		sharp;
	int			width;
	int			precision;
	char		type;
}				t_format;

int			ft_isflag(char flag);
int			ft_isprintf_type(int c);
int			ft_isdigit(int c);

void		ft_putnchar(char *str, size_t i);
void		ft_memset(int c, long n);
size_t		ft_strlen(const char *str);

void		ft_print_str(char *str, t_format f_flag);
void		ft_print_int(long n, t_format f_flag);
void		ft_print_ptr(size_t n, t_format f_flag);
void		ft_print_hex(long n, t_format f_flag);
void		ft_print_char(char c, t_format f_flag);
void		ft_print_percent(t_format f_flag);

void		ft_printf(const char *input, ...);
const char	*ft_parser(const char *input, va_list ap, t_format *form_f);

#endif //FT_PRINTF_H
