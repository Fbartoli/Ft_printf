#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

char		conv(va_list *params)
{
	char c;
	//c = (char)va_arg(*params, int);
	c = (char)va_arg(*params, int);
	return (c);
}

void	*conv_s(va_list *params)
{
	void *s;

	s = (wchar_t *)va_arg(*params,wchar_t*);
	//s = (char *)va_arg(*params, char *);
	return (s);
}
int	ft_pow(int nb, int pow)
{
		if (pow == 0)
					return (1);
			else
						return (nb * ft_pow(nb, pow - 1));
}
char*	ft_itoa_base(int value, int base, char maj)
{
		int i;
			char*nbr;
					int			neg;
	i = 1;
	neg = 0;
		if (value < 0)
				{
							if (base == 10)
											neg = 1;
									value *= -1;
										}
			while (ft_pow(base, i) - 1 < value)
						i++;
				nbr = (char*)malloc(sizeof(nbr) * i);
					nbr[i + neg] = '\0';
						while (i-- > 0)
								{
										nbr[i + neg] = (value % base) + (value % base > 9 ? maj - 10 : '0');
													value = value / base;
														}
							if (neg)
										nbr[0] = '-';
								return (nbr);
}

int ft_print(const char *format, ...)
{
	char *cat = "1252664";
	va_list params;
	if (format)
	{
		va_start(params, format);
		ft_putchar(conv(&params));
		ft_putchar('\n');
		ft_putstr(conv_s(&params));
		ft_putchar('\n');
		ft_putchar(conv(&params));
		ft_putchar('\n');
		//printf("%s\n", ft_itoa_base(cat, 16, 'A'));
		printf("%-12p\n", cat);
		printf("%12p\n", cat);
		//printf("%c\n", conv(&params));
		//printf("%s\n", conv_s(&params));
		//printf("%p\n", conv_p(&params))i;
		//printf("%10.c\n", 'c');
		va_end(params);
	}
	return (0);
}
int main ()
{
	char g = 'a';

	ft_print("test var_args", g , "shhhdsfh", 60);
	return (0);
}
