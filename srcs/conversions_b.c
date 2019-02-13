/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 09:13:33 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 14:47:21 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*conv_b(va_list *params)
{
	long	nbr;
	char	*bin;

	nbr = va_arg(*params, long);
	if (nbr > 2147483647 || nbr < -2147483648 || nbr == 0)
		return ("0");
	bin = ft_itoa_binaire(nbr);
	return (bin);
}
