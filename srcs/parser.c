/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:23 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/24 18:36:35 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init_struc(t_flag *struc)
{
	struc->flag = '\0';
	struc->min = 0;
	struc->prec = 0;
	struc->taille[0] = '\0';
	struc->conv = '\0';
}

static char	*input_field_prec(char *str, t_flag *struc)
{
	while (*str >= '0' && *str <= '9')
	{
		struc->min = struc->min * 10 + (*str - '0');
		str++;
	}
	if (*str == '.' && *(str + 1) > '0' && *(str + 1) <= '9')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			struc->prec = (struc->prec) * 10 + (*str - '0');
			str++;
		}
	}
	return (str);
}

static char	*input_to_struct(char *str, t_flag *struc)
{
	if (is_flag(*str) == 1)
	{
		struc->flag = *str;
		str++;
	}
	if (*str >= '0' && *str <= '9')
		str = input_field_prec(str, struc);
	if (is_taille(*str) == 1)
	{
		struc->taille[0] = *str;
		if (*(str + 1) == *str)
		{
			struc->taille[1] = *str;
			struc->taille[2] = '\0';
			str++;
		}
		else
			struc->taille[1] = '\0';
		str++;
	}
	if (is_conv(*str) == 1)
		struc->conv = *str;
	return (str);
}

char		*parser(char *str, t_flag *struc)
{
	if (*str == '%')
	{
		str++;
		init_struc(struc);
		str = input_to_struct(str, struc);
	}
	return (str);
}
