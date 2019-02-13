/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 08:49:59 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	ft_print_str_null(t_flag *struc)
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
	if (struc->right_pad && tofree != NULL)
		struc->i += ft_putnstr_fd(tofree, p, struc->fd);
	padding(struc);
	if (struc->right_pad == 0 && tofree != NULL)
		struc->i += ft_putnstr(tofree, p);
	free(tofree);
	//return (0);
}

void			ft_print_per(char c, t_flag *struc)
{
	struc->pad = struc->min - 1;
	//if (struc->conv == 'C')
	//	c = c - 32;
	if (struc->right_pad == 1)
		struc->i += ft_putchar_fd(c, struc->fd);
	while (struc->pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			struc->i += ft_putchar_fd('0', struc->fd);
		else
			struc->i += ft_putchar_fd(' ', struc->fd);
	}
	if (struc->right_pad == 0)
		struc->i += ft_putchar_fd(c, struc->fd);
}

void			ft_print_c(char c, t_flag *struc)
{
	struc->pad = struc->min - 1;
	if (struc->right_pad == 1)
		struc->i += ft_putchar_fd(c, struc->fd);
	while (struc->pad-- > 0)
	{
		if (struc->pad_zeroes == 1)
			struc->i += ft_putchar_fd('0', struc->fd);
		else
			struc->i += ft_putchar_fd(' ', struc->fd);
	}
	if (struc->right_pad == 0)
		struc->i += ft_putchar_fd(c, struc->fd);
}

void			ft_print_str(char *str, t_flag *struc)
{
	int p;

	if (str == NULL || ft_strcmp(str, "(null)") == 0)
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
		struc->i += ft_putnstr_fd(str, p, struc->fd);
	padding(struc);
	if (struc->right_pad == 0 && str != NULL)
		struc->i += ft_putnstr(str, p);
	if ((struc->conv == 'S' && ft_strcmp(str, "\0") != 0 ) || struc->conv == 'b')
		free(str);
	//return (0);
}

void			ft_print_p(char *str, t_flag *struc)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", struc->fd);
		return ;
	}
	struc->pad = struc->min - ft_strlen(str);
	if (struc->right_pad == 1)
		struc->i += ft_putnstr_fd(str, ft_strlen(str), struc->fd);
	padding(struc);
	if (struc->right_pad == 0)
		struc->i += ft_putnstr_fd(str, ft_strlen(str), struc->fd);
	if (ft_strcmp("0x0", str) != 0)
		free(str);
}
