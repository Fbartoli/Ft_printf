/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:40:09 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/07 10:03:07 by apsaint-         ###   ########.fr       */
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
		|| format == 'i' || format == 'o' || format == 'u'
		|| format == 'x' || format == 'X' || format == 'f'
		|| format == '%' || format == 'D' || format == 'U' || format == 'S'
		|| format == 'O')
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
			count += ft_putchar('0');
	}
	count += ft_putnbr(nb);
	if (struc->right_pad == 1)
	{
		while (tmp > 0)
		{
			count += ft_putchar(' ');
			tmp--;
		}
	}
	return (count);
}

char	*taille_to_int(char *str, t_flag *struc)
{
	if (*str == 'l' && *(str + 1) == 'l')
		struc->taille = LL;
	else if (*str == 'h' && *(str + 1) == 'h')
		struc->taille = HH;
	else if (*str == 'l')
		struc->taille = L;
	else if (*str == 'h')
		struc->taille = H;
	else if (*str == 'j')
		struc->taille = J;
	else if (*str == 'z')
		struc->taille = Z;
	else if (*str == 'L')
		struc->taille = LLL;
	if ((*str == 'l' && *(str + 1) == 'l')
		|| (*str == 'h' && *(str + 1) == 'h'))
		str += 2;
	else
		str += 1;
	return (str);
}
