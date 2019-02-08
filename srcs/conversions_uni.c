/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_S.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 09:13:10 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/08 09:13:11 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_code_uni(wchar_t u)
{
	if (u <= 127)
		return (1);
	else if (u <= 2047)
		return (2);
	else if (u <= 65535)
		return (3);
	else if (u <= 1114111)
		return (4);
	return (0);
}

char	*get_uni(wchar_t uni)
{
	char	*hex;

	hex = ft_strnew(5);
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
/*
void	unicode_conversion(wchar_t uni)
{
	int		unicode_size;

	unicode_size = get_code_uni(uni);
	if (unicode_size == 1)
	
	if (unicode_size == 2)
	{
		put_char_to_buf((e->nbr >> 6 & 31) + 192 & 2047, e);
		put_char_to_buf((e->nbr & 63) + 128 & 2047, e);
	}
	if (unicode_size == 3)
	{
		put_char_to_buf((e->nbr >> 12 & 15) + 224 & 65535, e);
		put_char_to_buf((e->nbr >> 6 & 63) + 128 & 65535, e);
		put_char_to_buf((e->nbr & 63) + 128 & 65535, e);
	}
	if (unicode_size == 4)
	{
		put_char_to_buf((e->nbr >> 18 & 7) + 240 & 1114111, e);
		put_char_to_buf((e->nbr >> 12 & 63) + 128 & 1114111, e);
		put_char_to_buf((e->nbr >> 6 & 63) + 128 & 1114111, e);
		put_char_to_buf((e->nbr & 63) + 128 & 1114111, e);
	}
}
*/
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
