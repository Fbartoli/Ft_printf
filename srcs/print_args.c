/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/31 19:14:27 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_putnstr(char *str, int len)
{
	int i;

	if (!str || len <= 0)
		return (0);
	i = 0;
	while (i < len && *str)
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int				ft_print_per(char c, t_flag *struc)
{
	struc->pad = struc->min - 1;
	if (struc->conv == 'C')
		c = c - 32;
	if (struc->right_pad == 1)
		struc->i += ft_putchar(c);
	while (struc->pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			struc->i += ft_putchar('0');
		else
			struc->i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		struc->i += ft_putchar(c);
	return (0);
}

int				ft_print_c(char c, t_flag *struc)
{
	struc->pad = struc->min - 1;
	if (struc->right_pad == 1)
		struc->i += ft_putchar(c);
	while (struc->pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			struc->i += ft_putchar('0');
		else
			struc->i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		struc->i += ft_putchar(c);
	return (0);
}

int				ft_print_str(char *str, t_flag *struc)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if ((int)ft_strlen(str) < struc->prec)
		struc->pad = struc->min;
	else
		struc->pad = struc->min - (ft_strlen(str) - struc->prec);
	if (struc->right_pad == 1)
		struc->i += ft_putnstr(str, ft_strlen(str) - struc->prec);
	while (struc->pad > 0)
		struc->i += padding(struc);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr(str, ft_strlen(str) - struc->prec);
	return (0);
}

int				ft_print_hex(char *str, t_flag *struc)
{
	int		pad;
	int		i;

	i = 0;
	pad = 0;
	if (ft_strcmp("0", str) == 0)
		return (ft_putnstr("0", 1));
	if (struc->force_prefix == 1 && struc->conv == 'x' && struc->pad_zeroes == 1)
		struc->pad -= ft_putnstr("0x", 2);
	if (struc->force_prefix == 1 && struc->conv == 'X' && struc->pad_zeroes == 1)
		struc->pad -= ft_putnstr("0X", 2);
	if (struc->force_prefix == 1 && struc->conv == 'x' && struc->pad_zeroes == 0)
		str = ft_strjoin("0x", str);
	if (struc->force_prefix == 1 && struc->conv == 'X' && struc->pad_zeroes == 0)
		str = ft_strjoin("0X", str);
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
