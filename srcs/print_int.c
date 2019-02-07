/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 16:06:37 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/07 08:58:48 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				check_plus_spacel(long nb, t_flag *struc)
{
	int	count;

	count = 0;
	if (struc->force_sign && nb >= 0)
		count += ft_putchar('+');
	else if (struc->blank_sign && nb >= 0)
		count += ft_putchar(' ');
	return (count);
}

static int		check_complet_charl(long nb, int count,
	char letter, t_flag *struc)
{
	int	tmp;

	if (ft_nbrlen(nb) < (struc->min + count))
	{
		if (letter == ' ' && struc->blank_sign && struc->force_prefix &&
			!struc->right_pad)
			struc->min--;
		if (struc->prec >= ft_nbrlen(nb))
		{
			tmp = struc->min - count - struc->prec;
			if (nb < 0)
				tmp--;
		}
		else
			tmp = struc->min - count - ft_nbrlen(nb);
		while (tmp-- > 0)
			ft_putchar(letter);
		return (struc->min);
	}
	else
		count += ft_nbrlen(nb);
	return (count);
}

static int		with_min_zero(long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->prec != 0)
		count = check_complet_charl(nb, count, ' ', struc);
	count += check_plus_spacel(nb, struc);
	if (nb < 0)
		ft_putchar('-');
	if (struc->prec == 0)
		count = check_complet_charl(nb, count, '0', struc);
	if (nb < 0)
		nb = -nb;
	ft_putnbrpf(nb, struc->prec);
	return (count);
}

static int		with_minl(long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->right_pad)
	{
		count += check_plus_spacel(nb, struc);
		ft_putnbrpf(nb, struc->prec);
		count = check_complet_charl(nb, count, ' ', struc);
	}
	else if (struc->pad_zeroes)
		count = with_min_zero(nb, struc);
	else
	{
		if ((struc->force_sign || struc->blank_sign) && nb >= 0)
			count++;
		count = check_complet_charl(nb, count, ' ', struc);
		count += check_plus_spacel(nb, struc);
		if ((struc->force_sign || struc->right_pad) && nb >= 0)
			count--;
		ft_putnbrpf(nb, struc->prec);
	}
	return (count);
}

int				ft_print_d(long nb, t_flag *struc)
{
	int	count;

	count = 0;
	if (!nb && !struc->prec)
		return (nb_null_prec_null(nb, struc));
	if (struc->min)
		count = with_minl(nb, struc);
	else
	{
		count = check_plus_spacel(nb, struc) + ft_nbrlen(nb);
		ft_putnbrpf(nb, struc->prec);
		if (struc->prec >= ft_nbrlen(nb))
			count += struc->prec - ft_nbrlen(nb);
	}
	if (nb && struc->prec > ft_nbrlen(nb))
	{
		count = (nb < 0) ? struc->prec + 1 : struc->prec;
		count = (struc->min > struc->prec) ? struc->min : count;
	}
	return (count);
}
