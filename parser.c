/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:09:23 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/23 16:36:18 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			give_param(char *format, char list[3])

static void	input_to_struct(const char *format, t_flag *struc)
{
	char list[];

	list[] = ["flag", "length", "conversion"]
	while (*format)
	{	if (is_flag(*format) == 1)
			struc->flag = *format;
		else
	}
}

int			parser(const char * format, va_list params, t_flag *struc)
{
	char *start = format;

	while (*format)
	{
		if (*format == '%')
		{
			input_to_struct(*format, *struc);
		}
		format++;
	}
}
