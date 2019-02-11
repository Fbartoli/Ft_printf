/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:55:43 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/11 16:41:05 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puto(char *str, t_flag *struc)
{
	int i;

	if ((struc->prec != 0) && ((size_t)struc->prec > ft_strlen(str)))
	{
		i = struc->prec - ft_strlen(str);
		while (i--)
			ft_putchar_fd('0', struc->fd);
	}
	ft_putstr(str);
}
