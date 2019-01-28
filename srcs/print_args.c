/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/28 15:30:41 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_per(char c, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - 1;
	if (struc->right_pad == 1)
		i += ft_putchar(c);
	while (pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		i += ft_putchar(c);
	return (i);
}

int		ft_print_c(char c, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - 1;
	if (struc->right_pad == 1)
		i += ft_putchar(c);
	while (pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		i += ft_putchar(c);
	return (i);
}

int		ft_print_str(char *str, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - ft_strlen(str);
	if (struc->right_pad == 1)
		i += ft_putstr(str);
	while (pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		i += ft_putstr(str);
	free(str);
	return (i);
}

int		ft_print_d(int nb, t_flag *struc)
{
	int i;
	int pad;

	i = 0;
	pad = struc->min - ft_nbrlen(nb);
	if (nb < 0 && struc->pad_zeroes == 1)
	{
		i += ft_putchar('-');
		nb *= -1;
		struc->force_sign = 0;
	}
	if (struc->right_pad == 1)
		i += ft_putnbr(nb);
	else if (struc->force_sign == 1 && nb >= 0)
	{
		i += ft_putchar('+');
		pad--;
	}
	else if (struc->blank_sign == 1 && nb > 0)
		i += ft_putchar(' ');
	while (pad-- > 0)
	{
		if (struc->pad_zeroes == 1 && struc->right_pad == 0)
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		i += ft_putnbr(nb);
	return (i);
}
