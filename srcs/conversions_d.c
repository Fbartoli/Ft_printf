/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:11:53 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/01 16:33:21 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long		conv_d(va_list *params, t_flag *struc)
{
	if (!ft_strcmp(struc->taille, "l") || struc->conv == 'D')
		return (va_arg(*params, long));
	else if (!ft_strcmp(struc->taille, "hh"))
		return ((char)va_arg(*params, int));
	else if (!ft_strcmp(struc->taille, "h"))
		return ((short)va_arg(*params, int));
	else
		return (va_arg(*params, int));
}
