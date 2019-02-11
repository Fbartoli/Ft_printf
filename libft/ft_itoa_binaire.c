/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_binaire.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 11:44:54 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/11 17:19:49 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_itoa_binaire(long value)
{
	int		i;
	int		neg;
	char	*bin;

	i = 2;
	if (value < 0)
	{
		neg = 1;
		value = -value;
	}
	else
		neg = 0;
	while (ft_pow(2, i) - 1 <= (unsigned long)value)
		i++;
	i++;
	if ( (bin = (char *)malloc(sizeof(bin) * (i + 1))) == NULL)
		return (NULL);
	bin[i] = '\0';
	bin[0] = neg + '0';
	while (--i > 0)
	{
		bin[i] = (value % 2) + (value % 2 > 9 ? 'A' - 10 : '0');
		value = value / 2;
	}
	return (bin);
}
