/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:18:40 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 12:31:13 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
//# include <wchar.h>
# include <locale.h>
int		main()
{
	//ft_printf("%p\n", 0);
	setlocale(LC_ALL, "");
	printf("My printf: %d\n",ft_printf("%C", (wint_t)-2));
	printf("My printf: %d\n",ft_printf("%C", (wint_t)-2));
	/*
	printf("My printf: %d\n",ft_printf("{% C}", 0));
	printf("Le printf: %d\n",printf("{% C}", 0));
	printf("My printf: %d\n", ft_printf("{%hhC}, {%hhC}", 0, L'米'));
	printf("Le printf: %d\n", printf("{%hhC}, {%hhC}", 0, L'米'));*/
	/*ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%15.3S\n", L"我是一只猫。");
	//ft_printf("my printf: %#X", 42);
	//printf("\n");
	//printf("Le printf: %#X", 42);
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	int i = 10 ;
	ft_printf("%p\n", 0);
	ft_printf("%lhl\n", 9223372036854775807);
	printf("%\n");
	ft_printf("%d\n", 42);
	ft_printf("{%0#10.0x}\n", 12345);
	printf("{%0#10.0x}\n", 12345);
//	ft_printf("%p\n", 0);
//	setlocale(LC_ALL, "");
//	ft_printf("\n");
//	ft_printf("%%\n");
	//ft_printf("%d\n", 42);
//	int i = 10 ;
	//ft_printf("%p\n", 0);
//	printf("min %d, min << %d", i / 2, (i >> 1));
	//ft_printf("%lhl\n", 9223372036854775807);
	//printf("%\n");
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%ls\n", L"我是一只猫。");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);
	ft_printf("{%#7.5X}\n", 0xab);
	ft_printf("My printf: %S\n", L"我是一只猫。");
	ft_printf("My printf: %b\n", -2);
	ft_printf("My printf: %-10b\n", 300);
	ft_printf("%s\n", ft_itoa_base(300, 2));*/
	//ft_printf("Le printf: {%05.S}", L"42 c est cool");
	//ft_printf("%s\n", ft_itoa_base(300, 2));
/*	int d1;
	int d2;
	d1 = ft_printf("{%#7.5X}\n", 0xab);
	d2 = printf("{%#7.5X}\n", 0xab);
	printf("%d, %d\n", d1, d2);*/
	//ft_printf("My printf: %S\n", L"我是一只猫。");
	/*ft_printf("My printf: %-10b\n", -2);
	ft_printf("My printf: %-10b\n", 300);
	ft_printf("%s\n", ft_itoa_base(300, 2));*/
	//ft_printf("Le printf: {%05.S}", L"42 c est cool");
	//ft_printf("Le printf: {%05.S}", L"42 c est cool");*/
	return (1);
}
