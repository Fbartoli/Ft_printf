/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/28 16:16:07 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
	int c = 128;
	int *b = &c;
	ft_printf("my printf: %-15p\n", b);
	printf("le printf: %-15p\n", b);
	ft_printf("my printf: %-15x\n", b);
	printf("le printf: %-15x\n", b);
	return (1);
}
