/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsbis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 17:36:52 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/05 18:03:31 by flbartol         ###   ########.fr       */
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
	if (struc->pad_zeroes == 1 && struc->right_pad == 0)
		ft_putchar('0');
	else if (struc->pad >= struc->prec_0 && struc->pad_zeroes == 1 &&
		struc->prec_default == 0 && struc->right_pad == 0)
		ft_putchar(' ');
	else
		ft_putchar(' ');
	struc->pad -= 1;
	return (1);
}

char	*get_min(char *str, t_flag *struc, va_list *params)
{
	struc->min = struc->min * 10 + (*str - '0');
	str++;
	struc->min_default = 0;
	if (*str == '*')
	{
		struc->min = va_arg(*params, int);
		struc->min_default = 0;
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
	else if (struc->conv == 'S')
		struc->conv = 's';
}
