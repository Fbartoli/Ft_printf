/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_S.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:13:10 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 10:45:51 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_code_uni(wchar_t u)
{
	if (u <= 0x7F && u >= 0)
		return (1);
	else if (u <= 0x7FF)
		return (2);
	else if (u <= 0xFFFF)
		return (3);
	else if (u <= 0x10FFFF)
		return (4);
	return (0);
}

char	*get_uni(wchar_t uni)
{
	char	*hex;

	hex = ft_strnew(get_code_uni(uni) + 1);
	if (get_code_uni(uni) == 1)
		hex[0] = (uni & 0x7F) | 0x00;
	if (get_code_uni(uni) == 2)
	{
		hex[0] = (uni >> 6 & 0x1F) | 0xC0;
		hex[1] = (uni & 0x3F) | 0x80;
	}
	if (get_code_uni(uni) == 3)
	{
		hex[0] = (uni >> 12 & 0x0F) | 0xE0;
		hex[1] = (uni >> 6 & 0x3F) | 0x80;
		hex[2] = (uni & 0x3F) | 0x80;
	}
	if (get_code_uni(uni) == 4)
	{
		hex[0] = (uni >> 18 & 0x07) | 0xF0;
		hex[1] = (uni >> 12 & 0x3F) | 0x80;
		hex[2] = (uni >> 6 & 0x3F) | 0x80;
		hex[3] = (uni & 0x3F) | 0x80;
	}
	return (hex);
}

char	*conv_unicode_single(va_list *params, t_flag *struc)
{
	wchar_t unicode;
	char	*code;
	char	*s;

	unicode = va_arg(*params, wchar_t);
	if (unicode == 0)
		struc->i += 1;
	code = get_uni(unicode);
	s = ft_strdup(code);
	free(code);
	return (s);
}

char	*conv_unicode(va_list *params)
{
	wchar_t *unicode;
	char	*s;
	char	*code;

	unicode = va_arg(*params, wchar_t *);
	if (unicode == NULL)
		return ("(null)");
	if (ft_strlen((char *)unicode) == 0)
		return ("\0");
	code = get_uni(*unicode++);
	s = ft_strdup(code);
	free(code);
	while (*unicode)
	{
		code = get_uni(*unicode++);
		s = ft_strjoinfree_uni(s, code);
	}
	return (s);
}
