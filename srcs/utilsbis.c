/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:52 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/08 17:19:33 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		nb_null_prec_null(long nb, t_flag *struc)
{
	int count;

	count = 0;
	if (struc->prec_default == 1)
		return (with_plus_zero(nb, struc));
	count = struc->min > 0 ? struc->min : 0;
	while (struc->min-- > 0)
		ft_putchar(' ');
	if (struc->blank_sign == 1)
		count += ft_putchar(' ');
	if (struc->force_sign == 1)
		count += ft_putchar('+');
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

int		padding(t_flag *struc)
{

	if (struc->pad_zeroes == 1 && struc->prec > 0)
	{
		while(struc->prec-- > 0)
			struc->i += ft_putchar(' ');
	}
	else if (struc->pad_zeroes == 0 && struc->prec > 0
		&& struc->conv == 'o')
	{
		while(struc->prec-- > 0)
			struc->i += ft_putchar('0');
	}
	if (struc->pad_zeroes == 1)
	{
		while(struc->pad-- > 0)
			struc->i += ft_putchar('0');
	}
	else
	{
		while(struc->pad-- > 0)
			struc->i += ft_putchar(' ');
	}
	return (0);
}

char	*get_min(char *str, t_flag *struc, va_list *params)
{
	struc->min = struc->min * 10 + (*str - '0');
	str++;
	if (*str == '*')
	{
		struc->min = va_arg(*params, int);
		str++;
	}
	return (str);
}

void	convup_to_min(t_flag *struc)
{
	if (struc->conv == 'F')
		struc->conv = 'f';
	else if (struc->conv == 'U')
	{
		struc->conv = 'u';
		struc->taille = L;
	}
	else if (struc->conv == 'D')
	{
		struc->conv = 'd';
		struc->taille = L;
	}
	else if (struc->conv == 'O')
	{
		struc->conv = 'o';
		struc->taille = L;
	}
}