/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:06:37 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 17:24:01 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_negjustified(int nb, t_flag *struc, int *i, int *test)
{
	*i += ft_putchar('-');
	struc->force_sign = 0;
	struc->is_neg = 1;
	nb *= -1;
	if (struc->right_pad == 0 && struc->prec_default == 0)
		*test += 1;
	struc->right_pad = 1;
	return (nb);
}

int	padding(t_flag *struc, int test, int pad)
{
	//printf("pad %d, test %d \n", pad, test);

	if (pad >= test && struc->pad_zeroes == 1 &&
		struc->prec_default == 0 && struc->right_pad == 0)
		ft_putchar(' ');
	else if (struc->pad_zeroes == 1 && struc->right_pad == 0)
	{	
		ft_putchar('0');
		test -= 1;
	}
	else
		ft_putchar(' ');
	return (1);
}

static int			format_0_prec(t_flag *struc)
{
	int i;
	int pad;

	i = 0;
	pad = 0;
	if (struc->min_default == 1)
		return (i);
	pad = struc->min;
	//printf("min %d\n",struc->min);
	while (pad-- > 0)
		i += ft_putchar(' ');
	return(i);
}

int			ft_print_d(int nb, t_flag *struc)
{
	int i;
	int pad;
	int test;                     //travailler avec le struc->min (possible opti)

	i = 0;
	if (struc->prec_default == 0 && struc->prec == 0 && nb == 0)
		return (format_0_prec(struc));
	if (struc->prec_default == 0)
		test = struc->prec - ft_nbrlen(nb);
	else
		test = 0;
	if (struc->min_default == 0)
		pad = struc->min - ft_nbrlen(nb);
	else
		pad = 0;
	if (struc->blank_sign == 1)
		pad -= 1;
	if (nb < 0 && (struc->pad_zeroes == 1 || struc->prec_default == 0))
		nb = int_negjustified(nb, struc, &i, &test);
	//printf("prec_def %d, sign %d, nb %d, blank%d, min %d\n", struc->prec_default, struc->force_sign, nb, struc->blank_sign, struc->min);
	if (struc->force_sign == 1 && nb >= 0 && struc->blank_sign == 0)
	{ 
		if (struc->prec_default == 1)
			i += ft_putchar('+');
		pad--;
	}
	if (struc->right_pad == 1)
	{
		if (struc->force_sign == 1)
			i += ft_putchar('+');
		while (test > 0 || (pad > 0 && struc->pad_zeroes == 1 && struc->is_neg == 1))
		{
			i += ft_putchar('0');
			pad--;
			test--;
		}
		i += ft_putnbr(nb);
	}
	if (struc->blank_sign == 1 && nb >= 0 && struc->force_sign == 0)
		i += ft_putchar(' ');
	//printf("pad %d, test %d\n", pad ,test);
	while (((pad--) - test) > 0 && test >=0)
		i += padding(struc, test, pad);
	if (struc->force_sign == 1 && nb >= 0 && (struc->blank_sign == 1 || test > 0))
		i += ft_putchar('+');
	if (struc->right_pad == 0)
	{
		while (test-- > 0 && (struc->is_neg == 0 || pad == test))
			i += ft_putchar('0');
		i += ft_putnbr(nb);
	}
	return (i);
}
