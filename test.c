#include <stdio.h>
#include <stdarg.h>
#include <wchar.h>
char		conv(va_list *params)
{
	wint_t c;
	c = (char)va_arg(*params, int);
	//c = (wchar_t)va_arg(*params, wint_t);
	return (c);
}

void	*conv_s(va_list *params)
{
	void *s;

	//s = (wchar_t *)va_arg(*params,wchar_t*);
	s = (char *)va_arg(*params, char *);
	return (s);
}

int ft_print(const char *format, ...)
{
	va_list params;
	if (format)
	{
		va_start(params, format);
		printf("%c\n", conv(&params));
		printf("%s\n", conv_s(&params));
		printf("%c\n", conv(&params));
		va_end(params);
	}
	return (0);
}
int main ()
{
	char g = 'a';

	ft_print("test var_args", g , "abcdef", 60);
	return (0);
}
