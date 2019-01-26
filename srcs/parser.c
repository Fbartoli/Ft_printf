/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:23 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/26 15:44:44 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	default_setting(t_flag *struc)
{
	if ((struc->conv == 'd' || struc->conv == 'i' || struc->conv == 'u'
			|| struc->conv == 'o' || struc->conv == 'x' || struc->conv == 'X')
			&& (struc->prec == 0))
		struc->prec = 1;
	else if (struc->conv == 'f' && (struc->prec == 0))
		struc->prec = 6;
	else if (struc->conv == 'c' && (struc->min == 0))
		struc->min = 1;
}

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
		default_setting(struc);
	}
	return (str);
}
