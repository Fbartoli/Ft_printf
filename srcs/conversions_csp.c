/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_csp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 14:09:23 by apsaint-          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/31 12:58:22 by apsaint-         ###   ########.fr       */
=======
/*   Updated: 2019/01/28 15:37:49 by flbartol         ###   ########.fr       */
>>>>>>> 4d6cd91235c9a655886dc1b8dedc2fa5bf39e974
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
	uint64_t	s;
	char		*hex;

	s = (uint64_t)va_arg(*params, void *);
	if (struc->conv == 'p' || struc->conv == 'x')
	{
		hex = ft_itoa_base_hex(s, 16, 'a', struc->conv);
		if (struc->conv == 'x' && struc->force_prefix == 1)
			hex = ft_strjoin("0x", hex);
	}
	else
	{
		hex = ft_itoa_base_hex(s, 16, 'A', struc->conv);
		if (struc->force_prefix == 1)
			hex = ft_strjoin("0X", hex);
	}
	return (hex);
}
