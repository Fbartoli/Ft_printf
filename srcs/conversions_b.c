/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:13:33 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/08 11:03:01 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conv_b(va_list *params)
{
	unsigned long	nbr;
	char			*bin;

	nbr = va_arg(*params, int);
	bin = ft_itoa_base(nbr, 2);
	return (bin);
}
