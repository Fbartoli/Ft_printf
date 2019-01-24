#include <stdio.h>
#include <stdarg.h>

char		conv(va_list *params)
{
	char c;
	c = va_arg(*params, int);
	return (c);
}

int ft_print(const char *format, ...)
{
	va_list params;
	if (format)
	{
		va_start(params, format);
		printf("%c\n", conv(&params));
		printf("%c\n", conv(&params));
		printf("%c\n", conv(&params));
		va_end(params);
	}
	return (0);
}
int main ()
{
	char g = 'a';

	ft_print("test var_args", g , 'g', 54);
	return (0);
}
