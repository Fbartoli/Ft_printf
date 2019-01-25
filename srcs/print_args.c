/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apsaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/25 15:01:44 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_flag struc)
{
	int pad;

	pad = struc.min - 1;
	if (struc.flag == '-')
		ft_putchar(c);
	while (pad--)
		ft_putchar(' ');
	if (struc.flag == '\0')
		ft_putchar(c);
}

void	ft_print_str(char *str, t_flag struc)
{
	int pad;

	pad = struc.min - ft_strlen(str);
	if (struc.flag == '-')
		ft_putstr(str);
	while (pad--)
		ft_putchar(' ');
	if (struc.flag == '\0')
		ft_putstr(str);
}
