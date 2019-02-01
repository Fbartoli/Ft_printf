/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 13:05:52 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/01 12:20:05 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_hex(uintmax_t num, uintmax_t base,
		char *taille, char conv)
{
	int		i;
	char	*str;
	char	*hash;
	char	lettre;

	i = 0;
	while ((uintmax_t)(ft_pow(base, i) - 1) < num)
		i++;
	if ((str = (char *)malloc(sizeof(str) * i)) == NULL)
		return (NULL);
	str[i] = '\0';
	if (conv == 'p' || conv == 'x')
		lettre = 'a';
	else
		lettre = 'A';
	while (i-- > 0)
	{
		str[i] = (num % base) + (num % base > 9 ? lettre - 10 : '0');
		num = num / base;
	}
	hash = ft_hash(num, base, lettre);
	if (conv == 'p' || ft_strcmp(taille, "ll")
			|| ft_strcmp(taille, "l"))
		str = ft_strjoin(hash, str);
	return (str);
}
