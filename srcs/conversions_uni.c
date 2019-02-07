/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_S.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:13:10 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/07 12:14:30 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_code_uni(wchar_t u)
{
	if (u < 0x80)
		return (0);
	else if (u < 0x0800)
		return (1);
	else if (u < 0x010000)
		return (2);
	else /*if (u < 0x110000)*/
		return (3);
}

char	*get_uni(wchar_t uni)
{
	char	*hex;

	hex = ft_strnew(5);
	if (get_code_uni(uni) == 0)
		hex[0] = (uni & 0x7F) | 0x00;
	else if (get_code_uni(uni) == 1)
	{
		hex[0] = ((uni >> 6) & 0x1F) | 0xC0;
		hex[1] = (uni & 0x3F) | 0x80;
	}
	else if (get_code_uni(uni) == 2)
	{
		hex[0] = ((uni >> 12) & 0x0F) | 0xE0;
		hex[1] = ((uni >> 6) & 0x3F) | 0x80;
		hex[2] = (uni & 0x3F) | 0x80;
	}
	else if (get_code_uni(uni) == 3)
	{
		hex[0] = ((uni >> 18) & 0x07) | 0xF0;
		hex[1] = ((uni >> 12) & 0x3F) | 0x80;
		hex[2] = ((uni >> 6) & 0x3F) | 0x80;
		hex[3] = (uni & 0x3F) | 0x80;
	}
	return (hex);
}

char	*conv_unicode(va_list *params)
{
	wchar_t *unicode;
	char	*s;

	unicode = va_arg(*params, wchar_t *);
	if (unicode == NULL)
		return ("(null)");
	if (get_uni(*unicode))
		s = ft_strdup(get_uni(*unicode));
	while (*unicode++)
		s = ft_strcat(s, get_uni(*unicode));
	return (s);
}
