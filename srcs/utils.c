/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:09 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 19:22:36 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char format)
{
	if (format == '#' || format == '-' || format == '+' || format == '0'
		|| format == ' ')
		return (1);
	else
		return (0);
}

int		is_taille(char format)
{
	if (format == 'h' || format == 'l' || format == 'L' || format == 'j'
		|| format == 'z')
		return (1);
	else
		return (0);
}

int		is_conv(char format)
{
	if (format == 'c' || format == 's' || format == 'p' || format == 'd'
		|| format == 'i' || format == 'o' || format == 'u' || format == 'x'
		|| format == 'X' || format == 'f' || format == '%')
		return (1);
	else
		return (0);
}

int			padding(t_flag *struc)
{
	if (struc->pad >= struc->prec_0 && struc->pad_zeroes == 1 &&
		struc->prec_default == 0 && struc->right_pad == 0)
		ft_putchar(' ');
	else if (struc->pad_zeroes == 1 && struc->right_pad == 0)
		ft_putchar('0');
	else
		ft_putchar(' ');
	struc->pad -= 1;
	return (1);
}
