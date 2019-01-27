/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/26 20:55:21 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
	char thisisacharacter = 0b1111010;
	ft_printf("%5c\n", thisisacharacter);
	printf("%#5c\n", thisisacharacter);
	return (1);
}