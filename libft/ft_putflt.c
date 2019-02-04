/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 11:15:14 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/03 13:39:43 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static void 	rounding_float(long double f)
{
	f *= 10;
	if (((long long)f % 10) == 0)
		ft_putchar('0');
	else if(((long long)f % 10) < 5)
		ft_putchar(48 + ((long long)f % 10 - 1));
	else
		ft_putchar(48 + ((long long)f % 10));
}

int				ft_putflt(long double f, int prec)
{
    int     ret;
    int     intpart;
    int     i;

    ret = 0;
    i = 0;
    intpart = (long long)f;
    ft_putnbr(intpart);
    ret = ft_nbrlen(intpart) + prec;
	if (prec != 0)
    	ret += ft_putchar('.');
    while (i++ < prec)
	{
		f *= 10;
		if (i == prec && (long long)f > 0)
			rounding_float(f);
		else if ((long long)f > 0)
		{
			ft_putchar(48 + ((long long)f % 10));
		}
		else
			ft_putchar('0');
	}
    return (ret);
}