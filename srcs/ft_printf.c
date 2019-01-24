/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/24 16:34:25 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_flag struc;
	char *start;

	start = (char*) format;
	va_list params;
	if (format)
	{
		va_start(params, format);
		parser(format, &struc);
		va_end(params);
	}
	printf("flag %c,taille %s,conv %c\n",struc.flag, struc.taille, struc.conv);
	return (0);
}
