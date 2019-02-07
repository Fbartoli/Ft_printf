/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 10:35:45 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/07 08:58:45 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_plus_spacef(long double nb, t_flag *struc)
{
	int	count;

	count = 0;
	if (struc->force_sign && nb >= 0)
		count += ft_putchar('+');
	else if (struc->blank_sign && nb >= 0)
		count += ft_putchar(' ');
	return (count);
}

static int	check_complet_charf(long double nb, int count, char letter,
	t_flag *struc)
{
	int	tmp;

	if (struc->min + count > ft_nbrlen(nb) + struc->prec + 1)
	{
		if (letter == ' ' && struc->blank_sign && struc->force_prefix &&
			!struc->right_pad)
			struc->min--;
		tmp = struc->min - count - ft_nbrlen(nb) - struc->prec - 1;
		while (tmp-- > 0)
			ft_putchar(letter);
		return (struc->min);
	}
	else
		count += ft_nbrlen(nb);
	return (count);
}

static int	with_min_zerof(long double nb, t_flag *struc)
{
	int count;

	count = 0;
	if (nb < 0)
		ft_putchar('-');
	count += check_plus_spacef(nb, struc);
	count = check_complet_charf(nb, count, '0', struc);
	if (nb < 0)
		nb = -nb;
	ft_putflt(nb, struc->prec);
	return (count);
}

static int	with_minf(long double nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->right_pad)
	{
		count += check_plus_spacef(nb, struc);
		ft_putflt(nb, struc->prec);
		count = check_complet_charf(nb, count, ' ', struc);
	}
	else if (struc->pad_zeroes)
		count = with_min_zerof(nb, struc);
	else
	{
		if ((struc->force_sign || struc->blank_sign) && nb >= 0)
			count++;
		count = check_complet_charf(nb, count, ' ', struc);
		count += check_plus_spacef(nb, struc);
		if ((struc->force_sign || struc->right_pad) && nb >= 0)
			count--;
		ft_putflt(nb, struc->prec);
	}
	return (count);
}

int			ft_print_f(long double nb, t_flag *struc)
{
	int count;

	count = 0;
	if (!nb && !struc->prec)
	{
		if (struc->prec_default == 1)
			return (with_plus_zero(nb, struc));
		count = struc->min > 0 ? struc->min : 0;
		while (struc->min-- > 0)
			ft_putchar(' ');
		return (count);
	}
	if (struc->min)
		count = with_minf(nb, struc);
	else
	{
		count = check_plus_spacef(nb, struc) + ft_nbrlen(nb) + struc->prec;
		ft_putflt(nb, struc->prec);
	}
	if (nb && struc->prec > ft_nbrlen(nb))
	{
		count = (nb < 0) ? struc->prec + 1 : struc->prec;
		count = (struc->min > struc->prec) ? struc->min : count;
	}
	return (count);
}
