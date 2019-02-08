/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/08 13:07:30 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int				ft_print_str_null(t_flag *struc)
{
	int		p;
	char 	*tofree;

	tofree = ft_strdup("(null)");
	if ((int)ft_strlen(tofree) <= struc->prec
		|| (!struc->prec && struc->prec_default == 1))
	{
		struc->pad = struc->min - ft_strlen(tofree);
		p = (int)ft_strlen(tofree);
	}
	else
	{
		p = struc->prec;
		struc->pad = struc->min - struc->prec;
	}
	if (struc->right_pad == 1 && tofree != NULL)
		struc->i += ft_putnstr(tofree, p);
	padding(struc);
	if (struc->right_pad == 0 && tofree != NULL)
		struc->i += ft_putnstr(tofree, p);
	return (0);
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
	int p;

	if (str == NULL)
		return (ft_print_str_null(struc));
	if ((int)ft_strlen(str) <= struc->prec ||
			(!struc->prec && struc->prec_default == 1))
	{
		struc->pad = struc->min - ft_strlen(str);
		p = (int)ft_strlen(str);
	}
	else
	{
		p = struc->prec;
		struc->pad = struc->min - struc->prec;
	}
	if (struc->right_pad == 1 && str != NULL)
		struc->i += ft_putnstr(str, p);
	padding(struc);
	if (struc->right_pad == 0 && str != NULL)
		struc->i += ft_putnstr(str, p);
	return (0);
}
/*
int				ft_print_uni(char *str, t_flag *struc)
{
	struc->pad = struc->min - ft_strlen(str);
	if (struc->right_pad == 1)
		struc->i += ft_putnstr(str, ft_strlen(str));
	while (struc->pad > 0)
		struc->i += padding(struc);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr(str, ft_strlen(str));
	return (0);
}
*/
int				ft_print_p(char *str, t_flag *struc)
{
	if (str == NULL)
		return (ft_putstr("(null)"));
	struc->pad = struc->min - ft_strlen(str);
	if (struc->right_pad == 1)
		struc->i += ft_putnstr(str, ft_strlen(str));
	padding(struc);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr(str, ft_strlen(str));
	return (0);
}
