/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/26 21:16:56 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_flag	struc;
	char	*start;
	int		nb_char;

	nb_char = 0;
	va_list params;
	start = (char *)format;
	va_start(params, format);
	nb_char = my_printf(start, &struc, &params);
	va_end(params);
	return (nb_char);
}
