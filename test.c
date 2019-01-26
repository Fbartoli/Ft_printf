#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
#include <unistd.h>

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
	wint_t c;
	//c = (char)va_arg(*params, int);
	c = (wchar_t)va_arg(*params, wint_t);
	return (c);
}

void	*conv_s(va_list *params)
{
	void *s;

	s = (wchar_t *)va_arg(*params,wchar_t*);
	//s = (char *)va_arg(*params, char *);
	return (s);
}

int ft_print(const char *format, ...)
{
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
		//printf("%c\n", conv(&params));
		//printf("%s\n", conv_s(&params));
		//printf("%p\n", conv_p(&params))i;
		printf("%10.c\n", 'c');
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
