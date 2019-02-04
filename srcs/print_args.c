/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/04 14:31:45 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_per(char c, t_flag *struc)
{
	struc->pad = struc->min - 1;
	if (struc->conv == 'C')
		c = c - 32;
	if (struc->right_pad == 1)
		struc->i += ft_putchar(c);
	while (struc->pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			struc->i += ft_putchar('0');
		else
			struc->i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		struc->i += ft_putchar(c);
	return (0);
}

int				ft_print_c(char c, t_flag *struc)
{
	struc->pad = struc->min - 1;
	if (struc->right_pad == 1)
		struc->i += ft_putchar(c);
	while (struc->pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			struc->i += ft_putchar('0');
		else
			struc->i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		struc->i += ft_putchar(c);
	return (0);
}

int				ft_print_str(char *str, t_flag *struc)
{
	int p;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if ((int)ft_strlen(str) <= struc->prec ||
			(!struc->prec && struc->prec_default == 1))
	{
		struc->pad = struc->min - ft_strlen(str);
		p = (int)ft_strlen(str);
	}
	else
	{
		p = struc->prec;
		struc->pad = struc->min - struc->prec;
	}
	if (struc->right_pad == 1)
		struc->i += ft_putnstr(str, p);
	while (struc->pad > 0)
		struc->i += padding(struc);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr(str, p);
	return (0);
}
