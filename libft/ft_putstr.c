/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:15:31 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/09 17:12:22 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putstr(char const *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		ft_putchar((char)s[i]);
		i++;
	}
	return (i);
}
