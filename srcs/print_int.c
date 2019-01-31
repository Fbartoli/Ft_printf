/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:06:37 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 19:21:16 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format_0_prec(t_flag *struc)
{
	int i;

	i = 0;
	struc->pad = 0;
	if (struc->min_default == 1)
		return (i);
	struc->pad = struc->min;
	while (struc->pad-- > 0)
		i += ft_putchar(' ');
	return (i);
}

static void	int_negjustified(int *nb, t_flag *struc)
{
	struc->i += ft_putchar('-');
	struc->force_sign = 0;
	struc->is_neg = 1;
	*nb *= -1;
	if (struc->right_pad == 0 && struc->prec_default == 0)
		struc->prec_0 += 1;
	struc->right_pad = 1;
}

static void	init_print_d(t_flag *struc, int *nb)
{
	if (struc->prec_default == 0)
		struc->prec_0 = struc->prec - ft_nbrlen(*nb);
	else
		struc->prec_0 = 0;
	if (struc->min_default == 0)
		struc->pad = struc->min - ft_nbrlen(*nb);
	else
		struc->pad = 0;
	if (struc->blank_sign == 1)
		struc->pad -= 1;
	if (*nb < 0 && (struc->pad_zeroes == 1 || struc->prec_default == 0))
		int_negjustified(nb, struc);
}

static void	int_justified(t_flag *struc, int nb)
{
	if (struc->force_sign == 1 && nb >= 0 && struc->blank_sign == 0)
	{
		if (struc->prec_default == 1)
			struc->i += ft_putchar('+');
		struc->pad--;
	}
	if (struc->right_pad == 1)
	{
		if (struc->force_sign == 1)
			struc->i += ft_putchar('+');
		while (struc->prec_0 > 0 || (struc->pad > 0 && struc->pad_zeroes == 1
			&& struc->is_neg == 1))
		{
			struc->i += ft_putchar('0');
			struc->pad -= 1;
			struc->prec_0 -= 1;
		}
		struc->i += ft_putnbr(nb);
	}
	if (struc->blank_sign == 1 && nb >= 0 && struc->force_sign == 0)
		struc->i += ft_putchar(' ');
}

int			ft_print_d(int nb, t_flag *struc)
{
	init_print_d(struc, &nb);
	if (struc->prec_default == 0 && struc->prec == 0 && nb == 0)
		return (format_0_prec(struc));
	int_justified(struc, nb);
	while (((struc->pad) - struc->prec_0) > 0 && struc->prec_0 >= 0)
		struc->i += padding(struc);
	if (struc->force_sign == 1 && nb >= 0
		&& (struc->blank_sign == 1 || struc->prec_0 > 0))
		struc->i += ft_putchar('+');
	if (struc->right_pad == 0)
	{
		while (struc->prec_0-- > 0 && (struc->is_neg == 0
			|| struc->pad == struc->prec_0))
			struc->i += ft_putchar('0');
		struc->i += ft_putnbr(nb);
	}
	return (0);
}
