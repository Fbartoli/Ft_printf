/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:11:53 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/28 17:44:06 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_d(va_list *params, t_flag *struc)
{
	int	d;
	int l;

	if (struc->taille[0] == 'l')
	{
		l = (long)va_arg(*params, long);
		return (l);
	}
	else if (struc->taille[0] == 'h' && struc->taille[1] == 'h')
		d = (char)va_arg(*params, int);
	else if (struc->taille[0] == 'h')
		d = (short)va_arg(*params, int);
	else
		d = (int)va_arg(*params, int);
	return (d);
}
