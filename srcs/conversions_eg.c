/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_eg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 09:53:55 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/04 10:28:07 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


long double		conv_e(va_list *params, t_flag *struc)
{
	if (!*struc->taille || !ft_strcmp(struc->taille, "l"))
		return (va_arg(*params, double));
	else if (struc->prec == 0)
		return (va_arg(*params, long));
	else if (!ft_strcmp(struc->taille, "L"))
		return (va_arg(*params, long double));
	else
		return (va_arg(*params, double));
}
