/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 11:10:05 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/08 16:45:17 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int				ft_print_o_null(t_flag *struc)
{
	if ((struc->prec_default == 1 || (struc->prec_default == 0 && struc->prec != 0)))
		struc->pad = struc->min - struc->prec - 1;
	else
		struc->pad = struc->min - struc->prec;
	if (struc->force_prefix && struc->prec > 0)
	{
		struc->prec--;
		struc->pad++;
	}
	if (struc->right_pad == 0)
		padding(struc);
	if ((struc->prec_default == 1) || (struc->min != 0 && struc->prec != 0)
		|| struc->force_prefix == 1)
		struc->i += ft_putnbr(0);
	if (struc->right_pad == 1)
			padding(struc);
	return (0);
}

static int		end_o(char *str, int count, t_flag *struc)
{
	if (struc->prec != 0 && (size_t)struc->prec > ft_strlen(str))
		count += struc->prec - ft_strlen(str);
	if (struc->prec != 0 && (size_t)struc->prec == ft_strlen(str))
		count++;
	if (struc->force_prefix && str[0] != '0' &&
		struc->prec < (int)ft_strlen(str))
		count++;
	if ((size_t)struc->min > ft_strlen(str) &&
		struc->prec < struc->min)
		count = struc->min;
	return (count);
}

static	int		check_complet_charo(char *nb, char letter, t_flag *struc)
{
	int	tmp;
	int count;

	if ( (size_t)(struc->min) > ft_strlen(nb))
	{
		if ((struc->prec != 0) && ((size_t)struc->prec > ft_strlen(nb)))
			tmp = struc->min - struc->prec;
		else
			tmp = struc->min - ft_strlen(nb);
		if (struc->force_prefix)
			tmp--;
		while (tmp-- > 0)
			ft_putchar(letter);
		if (struc->prec < struc->min)
			count = struc->min;
		else
			count = ft_strlen(nb);
	}
	else
		count = ft_strlen(nb);
	return (count);
}

static void		putzero_ifsharp(char *nb, t_flag *struc)
{
	if (struc->force_prefix && !(ft_strlen(nb) == 1 && nb[0] == '0') &&
		struc->prec <= (int)ft_strlen(nb))
		ft_putchar('0');
}

static int		with_mino(char *nb, t_flag *struc)
{
	int count;

	if (struc->right_pad)
	{
		putzero_ifsharp(nb, struc);
		ft_puto(nb, struc);
		count = check_complet_charo(nb, ' ', struc);
	}
	else if (struc->pad_zeroes && (struc->prec_default
			|| (struc->prec > struc->min)))
	{
		count = check_complet_charo(nb, '0', struc);
		putzero_ifsharp(nb, struc);
		ft_puto(nb, struc);
	}
	else
	{
		count = check_complet_charo(nb, ' ', struc);
		putzero_ifsharp(nb, struc);
		ft_puto(nb, struc);
	}
	return (count);
}

int				ft_print_o(unsigned long nb, t_flag *struc)
{
	char	*str;
	int		count;

	if (!nb)
		return (ft_print_o_null(struc));
	str = ft_itoa_base(nb, 8);
	if (struc->min)
		count = with_mino(str, struc);
	else
	{
		putzero_ifsharp(str, struc);
		ft_puto(str, struc);
		count = ft_strlen(str);
	}
	count = end_o(str, count, struc);
	free(str);
	return (count);
}
