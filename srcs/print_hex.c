/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:50:38 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/01 16:51:23 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prec_null(t_flag *struc)
{
	while (struc->min-- > 0)
		struc->i += ft_putchar(' ');
	return (0);
}

char		*ft_pad_hash(char *str, t_flag *struc)
{
	if (struc->force_prefix == 1 && struc->conv == 'x'
			&& struc->pad_zeroes == 1)
		struc->pad -= ft_putnstr("0x", 2);
	if (struc->force_prefix == 1 && struc->conv == 'X'
			&& struc->pad_zeroes == 1)
		struc->pad -= ft_putnstr("0X", 2);
	if (struc->force_prefix == 1 && struc->conv == 'x'
			&& struc->pad_zeroes == 0)
		str = ft_strjoin("0x", str);
	if (struc->force_prefix == 1 && struc->conv == 'X'
			&& struc->pad_zeroes == 0)
		str = ft_strjoin("0X", str);
	return (str);
}

int			ft_print_hex(char *str, t_flag *struc)
{
	if (ft_strcmp("0", str) == 0 && struc->prec_default == 1)
		return (ft_putnstr("0", 1));
	if (*str == '0' && !struc->prec)
		return (prec_null(struc));
	str = ft_pad_hash(str, struc);
	if (struc->pad < 0)
		struc->i += 2;
	if ((int)ft_strlen(str) < struc->prec)
		struc->pad += struc->min;
	else
		struc->pad += (struc->min - (ft_strlen(str)));
	if (struc->right_pad == 1)
		struc->i += ft_putnstr(str, ft_strlen(str));
	while (struc->pad > 0)
		struc->i += padding(struc);
	if (struc->right_pad == 0 && ft_strcmp("0", str))
		struc->i += ft_putnstr(str, ft_strlen(str));
	return (0);
}
