/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:02:55 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/24 18:41:22 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		my_printf(char *str, t_flag *struc)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str != '%')
			write(1, &(*(str)), 1);
		else
		{
			printf("\n");
			str = parser(str, struc);
			printf("%c, flag %c, min %d, preci %d, taille %s,conv %c\n", *str, struc->flag, struc->min, struc->prec,  struc->taille, struc->conv);
//			str = print_params(*str, struc, params, &i);   en dev
		}
		str++;
		i++;
	}
	write(1, "\n", 1);    	   			//pour les tests
	return (i);
}
