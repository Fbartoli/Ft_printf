/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:02:55 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/26 21:25:14 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(t_flag *struc, va_list *params)
{
	int i;

	i = 0;
	if (struc->conv == 's' || struc->conv == '%')
		i += ft_print_str(conv_s(params, struc), struc);
	else if (struc->conv == 'c')
		i += ft_print_c(conv_c(params, struc), struc);
	return (i);
}

int			my_printf(char *str, t_flag *struc, va_list *params)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != '%')
		{
			write(1, &(*(str)), 1);
			i++;
		}
		else
		{
			str = parser(str, struc);
			//printf("flag %c, min %d, prec %d,taille %s,conv %c\n", struc->flag, struc->min, struc->prec, struc->taille, struc->conv);
			i += ft_print(struc, params);
		}
		str++;
	}
	return (i);
}
