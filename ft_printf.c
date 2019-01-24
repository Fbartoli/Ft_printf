/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 14:28:53 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/23 18:02:04 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_flag struc;
	char *start;

	start = format;
	va_list params;
	parser(format, &struc);	
	va_end(params);
	printf("flag %c,taille %s,conv %c\n",struc.flag, struc.taille, struc.conv);
	return (0);
}
