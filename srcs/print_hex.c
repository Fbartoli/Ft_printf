/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 09:50:38 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/01 12:10:56 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pad_hash(char *str, t_flag *struc)
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

int		ft_print_hex(char *str, t_flag *struc)
{
	if (ft_strcmp("0", str) == 0)
		return (ft_putnstr("0", 1));
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
	if (struc->right_pad == 0)
		struc->i += ft_putnstr(str, ft_strlen(str));
	return (0);
}
