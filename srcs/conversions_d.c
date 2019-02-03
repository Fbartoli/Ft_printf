/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:11:53 by *paramssain       #+#    #+#             */
/*   Updated: 2019/02/03 20:47:00 by flbartol         ###   ########.fr       */
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

long double		conv_f(va_list *params, t_flag *struc)
{
	if (!*struc->taille || !ft_strcmp(struc->taille, "l"))
		return (va_arg(*params, double));
	else if (struc->prec == 0)
		return (va_arg(*params, long));
	else if (!ft_strcmp(struc->taille, "L"))
		return (va_arg(*params, long double));
	else
		return(va_arg(*params, double));
}