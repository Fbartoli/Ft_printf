/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/28 17:41:58 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnstr(char *str, int len)
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


int		ft_print_per(char c, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - 1;
	if (struc->right_pad == 1)
		i += ft_putchar(c);
	while (pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		i += ft_putchar(c);
	return (i);
}

int		ft_print_c(char c, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	pad = struc->min - 1;
	if (struc->right_pad == 1)
		i += ft_putchar(c);
	while (pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			i += ft_putchar('0');
		else
			i += ft_putchar(' ');
	}
	if (struc->right_pad == 0)
		i += ft_putchar(c);
	return (i);
}

int		ft_print_str(char *str, t_flag *struc)
{
	int pad;
	int i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if ((int)ft_strlen(str) < struc->prec)
		pad = struc->min;
	else
		pad = struc->min - (ft_strlen(str) - struc->prec);
	if (struc->right_pad == 1)
		i += ft_putnstr(str, ft_strlen(str) - struc->prec);
	while (pad-- > 0)
	i += padding(struc);
	if (struc->right_pad == 0)
		i += ft_putnstr(str, ft_strlen(str) - struc->prec);
	if (struc->conv == 'p')
		free(str);
	return (i);
}
