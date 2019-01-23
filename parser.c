/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:23 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/23 18:02:08 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

static void	input_to_struct(const char *format, t_flag *struc)
{
	while (is_conv(*format) != 1)
	{
		if (is_flag(*format) == 1)
		{
			struc->flag = *format;
		}
		else if (is_taille(*format) == 1)
		{
			struc->taille[0] = *format;
			if (*format + 1 == *format)
			{
				struc->taille[1] = *format;
				struc->taille[2] = '\0';
			}
			else
				struc->taille[1] = '\0';
			format++;
		}
		format++;
	}
	if (is_conv(*format) == 1)
		struc->conv = *format;
}

int			parser(const char * format, t_flag *struc)
{
	char *start;	//pour stocker l'adresse du caracteres apres le %

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			start = format;
			input_to_struct(format, struc); //pour stocker flag, taille et conv dans la struct.
		}
		format = start;						// reset l'adresse de format pour pouvoir parcourir la chaine et trouver le . de la precision
//		if (*format == '.')
//		{
//
//		}
		format++
	}
	return (0);
}
