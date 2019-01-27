/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/27 01:48:57 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_c(char c, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - 1;
	if (struc->flag == '-')
		i += ft_putchar(c);
	while (pad-- > 0)
	{
		if (struc->flag == '0')
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->flag == '\0' || struc->flag == '0' || struc->flag == ' '
		|| struc->flag == '#')
		i += ft_putchar(c);
	return (i);
}

int		ft_print_str(char *str, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - ft_strlen(str);
	if (struc->flag == '-')
		i+= ft_putstr(str);
	while (pad-- > 0)
	{
		if (struc->flag == '0')
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->flag == '\0' || struc->flag == '0' || struc->flag == ' '
		|| struc->flag == '#')
		i += ft_putstr(str);
	return (i);
}

int		ft_print_d(int nb, t_flag *struc)
{
	char *str;
	int i;

	i = 0;
	str = ft_itoa(nb);
	ft_print_str(str, struc);
	return (i);
}