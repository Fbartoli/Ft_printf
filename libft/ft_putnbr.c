/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:22:26 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/28 17:42:11 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int n)
{
	int i;

	i = 0;
	if (n > 2147483647 || n < -2147483648)
		return (0);
	if (n == -2147483648)
	{
		i = ft_putstr("-2147483648");
		return (i);
	}
	if (n < 0)
	{
		n = n * -1;
		i = ft_putchar('-');
	}
	if (n < 10)
	{
		i += ft_putchar(n + '0');
		return (i);
	}
	i += ft_putnbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
