/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:20:15 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/09 18:27:58 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# define L 1
# define LL 2
# define H 3
# define HH 4
# define J 5
# define Z 6
# define LLL 7

typedef struct	s_flag
{
	int		force_prefix;
	int		pad_zeroes;
	int		right_pad;
	int		force_sign;
	int		blank_sign;
	int		min;
	int		prec;
	int		prec_default;
	int		taille;
	char	conv;
	int		is_neg;
	int		prec_0;
	int		pad;
	int		i;
	int		fd;
}				t_flag;

char			*get_min(char *str, t_flag *struc, va_list *params);
char			*parser(char *str, t_flag *struc, va_list *params);
int				is_flag(char format);
int				is_taille(char format);
int				is_conv(char format);
int				ft_printf(const char *format, ...);
int				ft_printfd(int fd, const char *format, ...);
int				conv_c(va_list *params, t_flag *struc);
void			*conv_s(va_list *params, t_flag *struc);
char			*conv_unicode(va_list *params);
long			conv_d(va_list *params, t_flag *struc);
unsigned long	conv_ud(va_list *params, t_flag *struc);
long double		conv_f(va_list *params, t_flag *struc);
void			*conv_p(va_list *params, t_flag *struc);
void			*conv_u(va_list *params, t_flag *struc);
char			*conv_b(va_list *params);
void			ft_print_c(char c, t_flag *struc);
int				ft_print_ud(unsigned long nb, t_flag *struc);
int				ft_print_o(unsigned long nb, t_flag *struc);
void			ft_print_str(char *str, t_flag *struc);
void			ft_print_p(char *str, t_flag *struc);
int				ft_print_hex(char *str, t_flag *struc);
int				ft_print_d(long nb, t_flag *struc);
int				ft_print_f(long double nb, t_flag *struc);
void			ft_print_per(char c, t_flag *struc);
void			ft_puto(char *str, t_flag *struc);
char			*ft_pad_hash(char *str, t_flag *struc);
int				padding(t_flag *struc);
int				with_plus_zero(long nb, t_flag *struc);
int				check_plus_spacel(long nb, t_flag *struc);
char			*taille_to_int(char *str, t_flag *struc);
int				is_default(t_flag *struc);
void			convup_to_min(t_flag *struc);
int				nb_null_prec_null(long nb, t_flag *struc);
#endif
