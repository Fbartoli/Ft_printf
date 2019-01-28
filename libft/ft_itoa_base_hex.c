/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:05:52 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/28 16:13:43 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_hex(uintmax_t num, uintmax_t base, char lettre, char conv)
{
	int			i;
	char		*str;
	char		*hex;

	hex = "0x";
	i = 1;
	while ((uintmax_t)(ft_pow(base, i) - 1) < num)
		i++;
	if ((str = (char *)malloc(sizeof(str) * i)) == NULL)
			return (NULL);
	str[i] = '\0';
	while (i-- > 0)
	{
		str[i] = (num % base) + (num % base > 9 ? lettre - 10 : '0');
		num = num / base;
	}
	if (conv == 'p')
		str = ft_strjoin(hex, str);
	return (str);
}
