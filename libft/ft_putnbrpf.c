/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrpf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:22:26 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/04 15:20:29 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrpf(long nb, int prec)
{
	short count;

	if (prec > 0)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		count = ft_nbrlen(nb);
		count = prec - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nb || prec)
		ft_putnbr(nb);
}
