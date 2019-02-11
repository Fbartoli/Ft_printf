/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:50:38 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/11 15:24:49 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		padding_hex(t_flag *struc, size_t len)
{
	if ((size_t)struc->prec <= len && struc->prec_default == 0)
		struc->pad_zeroes = 0;
	if (struc->pad_zeroes == 1)
	{
		while(struc->pad-- > 0)
			struc->i += ft_putchar('0');
	}
	else
	{
		while(struc->pad-- > 0)
			struc->i += ft_putchar(' ');
	}
	return (0);
}

static int	prec_null(t_flag *struc)
{
	if(struc->min)
	{
		while (struc->min-- > 0)
			struc->i += ft_putchar(' ');
	}
	else
	{
		while (struc->prec-- > 0)
			struc->i += ft_putchar('0');
	}
	return (0);
}

char		*ft_pad_hash(char *str, t_flag *struc)
{
	if (struc->force_prefix == 1 && struc->conv == 'x'
			&& (struc->pad_zeroes == 1 || struc->prec > 0))
		struc->pad -= ft_putnstr("0x", 2);
	if (struc->force_prefix == 1 && struc->conv == 'X'
			&& struc->pad_zeroes == 1)
		struc->pad -= ft_putnstr("0X", 2);
	if (struc->force_prefix == 1 && struc->conv == 'x'
			&& struc->pad_zeroes == 0 && struc->prec == 0)
		str = ft_strjoinfree("0x", str);
	if (struc->force_prefix == 1 && struc->conv == 'X'
			&& struc->pad_zeroes == 0)
		str = ft_strjoinfree("0X", str);
	return (str);
}

char		*ft_hex_prec(char *str, t_flag *struc)
{
	int		p;

	p = struc->prec - ft_strlen(str);
	while (p-- > 0)
		str = ft_strjoin("0", str);
	return (str);
}

int			ft_print_hex(char *str, t_flag *struc)
{
	size_t len;

	len = ft_strlen(str);
	if (ft_strcmp("0", str) == 0 && struc->prec_default == 1)
		return (ft_putnstr("0", 1));
	if (*str == '0' && !struc->prec)
		return (prec_null(struc));
	if (*str == '0' && struc->prec)
		return (prec_null(struc));
	str = ft_pad_hash(str, struc);
	if (struc->pad < 0)
		struc->i += 2;
	if (struc->prec > (int)ft_strlen(str))
		str = ft_hex_prec(str, struc);
	if ((int)ft_strlen(str) < struc->prec)
		struc->pad += struc->min;
	else
		struc->pad += (struc->min - ft_strlen(str));
	if (struc->right_pad == 1)
		struc->i += ft_putnstr(str, ft_strlen(str));
	struc->i += padding_hex(struc, len);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr(str, ft_strlen(str));
	free(str);
	return (0);
}
