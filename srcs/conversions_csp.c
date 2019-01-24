/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_csp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:09:23 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/24 17:09:41 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void	conv_c(va_list *params, t_flag struc)
{
	wint_t c;

	if (struc.taille[0] == 'l' || struc.conv == 'C')
		c = (wchar_t)va_arg(*params, wint_t);
	else
		c = (char)va_arg(*params, int);
}

void	conv_s(va_list *params, t_flag struc)
{
	void *s;

	if (struc.taille[0] == 'l' || struc.conv == 'S')
		s = (wchar_t *)va_arg(*params, wchar_t *);
	else
		s = (char *)va_arg(*params, char *);
}
