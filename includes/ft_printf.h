/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:20:15 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/23 17:36:06 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_flag
{
				char	flag;
				int		min;
				int		prec;
				char	taille[3];
				char	conv;
}				t_flag;

int		parser(const char *format, t_flag *struc);
int		is_flag(char format);
int		is_taille(char format);
int		is_conv(char format);
int		ft_printf(const char *format, ...);

#endif
