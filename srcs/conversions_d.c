/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:11:53 by *paramssaint-          #+#    #+#             */
/*   Updated: 2019/02/02 11:15:18 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long 	conv_d(va_list *params, t_flag *struc)
{
	if (!*struc->taille)
		return (va_arg(*params, int));
	if (!ft_strcmp(struc->taille, "l") || !ft_strcmp(struc->taille, "ll")
	|| !ft_strcmp(struc->taille, "j")||	struc->conv == 'D')
		return (va_arg(*params, long));
	else if (!ft_strcmp(struc->taille, "hh"))
		return ((char)va_arg(*params, int));
	else if (!ft_strcmp(struc->taille, "h"))
		return ((short)va_arg(*params, int));
	else
		return (va_arg(*params, size_t));
}

unsigned long	conv_ud(va_list *params, t_flag *struc)
{
	if (!*struc->taille)
		return (va_arg(*params, unsigned int));
	else if (!ft_strcmp(struc->taille, "l") || !ft_strcmp(struc->taille, "ll") ||
				!ft_strcmp(struc->taille, "j"))
		return (va_arg(*params, unsigned long));
	else if (!ft_strcmp(struc->taille, "h"))
		return ((unsigned short)va_arg(*params, unsigned int));
	else if (!ft_strcmp(struc->taille, "hh"))
		return ((unsigned char)va_arg(*params, unsigned int));
	else
		return (va_arg(*params, ssize_t));
}