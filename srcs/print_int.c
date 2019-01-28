/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:06:37 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/28 17:45:29 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_negjustified(int nb, t_flag *struc, int *i)
{
	*i += ft_putchar('-');
	struc->force_sign = 0;
	nb *= -1;
	return (nb);
}

int	padding(t_flag *struc)
{
	if (struc->pad_zeroes == 1 && struc->right_pad == 0)
		ft_putchar('0');
	else
		ft_putchar(' ');
	return (1);
}

int			ft_print_d(int nb, t_flag *struc)
{
	int i;
	int pad;                     //travailler avec le struc->min (possible opti)

	i = 0;
	pad = struc->min - ft_nbrlen(nb);
	if (nb < 0 && struc->pad_zeroes == 1)
		nb = int_negjustified(nb, struc, &i);
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
		i += padding(struc);
	if (struc->right_pad == 0)
		i += ft_putnbr(nb);
	return (i);
}
