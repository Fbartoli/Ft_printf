/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:09 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/13 14:45:55 by flbartol         ###   ########.fr       */
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
		|| format == 'i' || format == 'o' || format == 'u' || format == 'b'
		|| format == 'x' || format == 'X' || format == 'f' || format == 'F'
		|| format == '%' || format == 'D' || format == 'U' || format == 'S'
		|| format == 'O' || format == 'C')
		return (1);
	else
		return (0);
}

int		is_default(t_flag *struc)
{
	if (struc->force_prefix == 0 && struc->force_sign == 0
		&& struc->pad_zeroes == 0 && struc->right_pad == 0
		&& struc->blank_sign == 0 && struc->min == 0
		&& struc->prec == 0 && struc->taille == 0
		&& struc->conv == '\0' && struc->is_neg == 0
		&& struc->prec_default == 1 && struc->pad == 0)
		return (1);
	return (0);
}

int		with_plus_zero(long nb, t_flag *struc)
{
	int count;
	int tmp;

	count = 0;
	tmp = struc->min - ft_nbrlen(nb);
	count += check_plus_spacel(nb, struc);
	if (struc->pad_zeroes == 1)
	{
		while ((struc->min - count - ft_nbrlen(nb)) > 0)
			count += ft_putchar_fd('0', struc->fd);
	}
	else if (struc->right_pad == 0)
	{
		while (tmp-- > 0)
			count += ft_putchar_fd(' ', struc->fd);
	}
	count += ft_putnbr(nb);
	if (struc->right_pad == 1)
	{
		while (tmp-- > 0)
			count += ft_putchar_fd(' ', struc->fd);
	}
	return (count);
}
