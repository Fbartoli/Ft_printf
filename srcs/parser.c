/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:23 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/23 18:49:34 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	char *start;

	if ((start = ft_strchr(format, '%')) == NULL)
	{
		ft_putstr(format);
		write(1, "\n", 1);
	}
	else if (*start == '%')
	{
		start++;
		input_to_struct(start, struc);
	}
	printf("%c\n", *start);
	return (0);
}
