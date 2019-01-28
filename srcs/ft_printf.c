/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/28 16:57:26 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_print(t_flag *struc, va_list *params)
{
	int i;

	i = 0;
	if (struc->conv == 's')
		i += ft_print_str(conv_s(params, struc), struc);
	else if (struc->conv == 'p')
		i += ft_print_str(conv_p(params, struc), struc);
	else if (struc->conv == 'c')
		i += ft_print_c(conv_c(params, struc), struc);
	else if (struc->conv == '%')
		i += ft_print_per('%', struc);
	else if (struc->conv == 'd' || struc->conv == 'i')
		i += ft_print_d(conv_d(params, struc), struc);
	return (i);
}

static int		my_printf(char *str, t_flag *struc, va_list *params)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*(str)), 1);
			i++;
		}
		else
		{
			str = parser(str, struc);
			i += ft_print(struc, params);
		}
		str++;
	}
	return (i);
}

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
