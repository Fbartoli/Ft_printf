/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 12:29:06 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/31 12:37:10 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_hash(uint64_t num, uint64_t base, char lettre)
{
	int			i;
	char		*hash;
	uint64_t	val;

	val = num;
	i = 0;
	while (val > 0)
	{
		val = val / base;
		i++;
	}
	if ((hash = (char *)malloc(sizeof(hash) * i)) == NULL)
		return (NULL);
	hash[i] = '\0';
	while (i--)
	{
		hash[i] = (num % base) + (num % base > 9 ? lettre - 10 : '0');
		num = num / base;
	}
	return (hash);
}
