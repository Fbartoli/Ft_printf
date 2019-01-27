/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:11:53 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/27 19:00:08 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_d(va_list *params, t_flag *struc)
{
	int	d;

	if (struc->taille[0] == 'l')
		d = (long)va_arg(*params, long);
	else if (struc->taille[0] == 'h' && struc->taille[1] == 'h')
		d = (char)va_arg(*params, int);
	else if (struc->taille[0] == 'h')
		d = (short)va_arg(*params, int);
	else
		d = (int)va_arg(*params, int);
	return (d);
}