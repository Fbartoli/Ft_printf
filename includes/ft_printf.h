/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:20:15 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 15:19:39 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct			s_flag
{
				int		force_prefix;
				int		pad_zeroes;
				int		right_pad;
				int		force_sign;
				int		blank_sign;
				int		min;
				int		prec;
				int 	prec_default;
				char	taille[3];
				char	conv;
				int		is_neg;
}						t_flag;

char	*parser(char *str, t_flag *struc);
int		is_flag(char format);
int		is_taille(char format);
int		is_conv(char format);
int		ft_printf(const char *format, ...);
int		conv_c(va_list *params, t_flag *struc);
void	*conv_s(va_list *params, t_flag *struc);
int		ft_print_c(char c, t_flag *struc);
int		ft_print_str(char *str, t_flag *struc);
int		ft_print_hex(char *str, t_flag *struc);
int		ft_print_d(int nb, t_flag *struc);
int		ft_print_per(char c, t_flag *struc);
int		conv_d(va_list *params, t_flag *struc);
void	*conv_p(va_list *params, t_flag *struc);
int		padding(t_flag *struc, int test, int pad);
#endif
