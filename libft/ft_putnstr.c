/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 10:13:14 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/01 10:17:50 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnstr(char *str, int len)
{
	int i;

	i = 0;
	if (!str || len <= 0)
		return (0);
	while (i < len && *str)
		ft_putchar(str[i++]);
	return (i);
}
