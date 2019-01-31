/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:05:52 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/31 12:47:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_hex(uint64_t num, uint64_t base, char lettre, char conv)
{
	int		i;
	char	*str;
	char	*hex;
	char	*hash;

	i = 0;
	hex = "0x";
	while ((uint64_t)(ft_pow(base, i) - 1) < num)
		i++;
	if ((str = (char *)malloc(sizeof(str) * i)) == NULL)
		return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (num % base) + (num % base > 9 ? lettre - 10 : '0');
		num = num / base;
	}
	hash = ft_hash(num, base, lettre);
	if (conv == 'p')
	{
		str = ft_strjoin(hash, str);
		str = ft_strjoin(hex, str);
	}
	return (str);
}
