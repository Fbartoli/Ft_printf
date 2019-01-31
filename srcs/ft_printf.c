/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 18:41:52 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_struc(t_flag *struc)
{
	struc->force_prefix = 0;
	struc->force_sign = 0;
	struc->pad_zeroes = 0;
	struc->right_pad = 0;
	struc->blank_sign = 0;
	struc->min = 0;
	struc->prec = 0;
	struc->taille[0] = '\0';
	struc->conv = '\0';
	struc->is_neg = 0;
	struc->prec_default = 1;
	struc->min_default = 1;
	struc->pad = 0;
	struc->prec_0 = 0;
}

static int		ft_print(t_flag *struc, va_list *params)
{
	if (struc->conv == 's')
		struc->i += ft_print_str(conv_s(params, struc), struc);
	else if (struc->conv == 'x' || struc->conv == 'X')
		struc->i += ft_print_hex(conv_p(params, struc), struc);
	else if (struc->conv == 'p')
		struc->i += ft_print_str(conv_p(params, struc), struc);
	else if (struc->conv == 'c')
		struc->i += ft_print_c(conv_c(params, struc), struc);
	else if (struc->conv == '%')
		struc->i += ft_print_per('%', struc);
	else if (struc->conv == 'd' || struc->conv == 'i')
		struc->i += ft_print_d(conv_d(params, struc), struc);
	else if (struc->conv == '\0')
		return (struc->i);
	return (0);
}

static int		my_printf(char *str, t_flag *struc, va_list *params)
{
	struc->i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*(str)), 1);
			struc->i += 1;
		}
		else
		{
			init_struc(struc);
			str = parser(str, struc);
			struc->i += ft_print(struc, params);
		}
		str++;
	}
	return (struc->i);
}

int				ft_printf(const char *format, ...)
{
	t_flag	struc;
	int		nb_char;
	char	*start;
	va_list params;

	start = (char *)format;
	nb_char = 0;
	init_struc(&struc);
	va_start(params, format);
	nb_char = my_printf(start, &struc, &params);
	va_end(params);
	return (nb_char);
}
