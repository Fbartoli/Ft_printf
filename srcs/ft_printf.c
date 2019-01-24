/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/24 18:30:17 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_flag	struc;
	char	*start;
	int		nb_char;
	va_list params;

	start = (char *)format;
//	parser(start, &struc);
	nb_char = my_printf(start, &struc);
	va_end(params);
	return (0);
}
