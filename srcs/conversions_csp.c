/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_csp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:09:23 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/28 15:37:49 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>
#include <limits.h>

int		conv_c(va_list *params, t_flag *struc)
{
	wint_t	c;

	if (struc->taille[0] == 'l' || struc->conv == 'C')
		c = (wchar_t)va_arg(*params, wint_t);
	else
	{
		c = (char)va_arg(*params, int);
	}
	return (c);
}

void	*conv_s(va_list *params, t_flag *struc)
{
	void	*s;

	if (struc->taille[0] == 'l' || struc->conv == 'S')
		s = (wchar_t *)va_arg(*params, wchar_t *);
	else
		s = (char *)va_arg(*params, char *);
	return (s);
}

void	*conv_p(va_list *params, t_flag *struc)
{
	uintmax_t	s;
	char		*hex;

	s = (unsigned long)va_arg(*params, unsigned long int);
	s = (uintmax_t)s;
	if (struc->conv == 'p' || struc->conv == 'x')
		hex = ft_itoa_base_hex(s, 16, 'a', struc->conv);
	else
		hex = ft_itoa_base_hex(s, 16, 'A', struc->conv);
	return (hex);
}
