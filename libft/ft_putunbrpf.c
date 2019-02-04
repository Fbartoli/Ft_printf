/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbrpf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:51:54 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/04 15:20:35 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putunbrpf(unsigned long nb, int prec)
{
	int count;

	if (prec > 0)
	{
		count = ft_unbrlen(nb);
		count = prec - count;
		while (count-- > 0)
			ft_putchar('0');
	}
	if (nb || prec)
		ft_putunbr(nb);
}
