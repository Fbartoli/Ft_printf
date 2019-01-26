/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:05:07 by apsaint-          #+#    #+#             */
/*   Updated: 2019/01/26 18:34:40 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, t_flag *struc)
{
	int pad;

	pad = struc->min - 1;
	if (struc->flag == '-')
		ft_putchar(c);
	while (pad-- > 0)
	{
		if (struc->flag == '0')
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (struc->flag == '\0' || struc->flag == '0' || struc->flag == ' '
		|| struc->flag == '#')
		ft_putchar(c);
}

void	ft_print_str(char *str, t_flag *struc)
{
	int pad;

	pad = struc->min - ft_strlen(str);
	if (struc->flag == '-')
		ft_putstr(str);
	while (pad-- > 0)
	{
		if (struc->flag == '0')
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	if (struc->flag == '\0' || struc->flag == '0' || struc->flag == ' '
		|| struc->flag == '#')
		ft_putstr(str);
}

void	ft_print_d(int nb, t_flag *struc)
{
	char *str;

	str = ft_itoa(nb);
	ft_print_str(str, struc);
}