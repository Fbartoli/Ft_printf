/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 17:20:52 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		main()
{
	int c = 128;
	int *b = &c;
	ft_printf("my printf: %-15p\n", "123");
	printf("le printf: %-15p\n", "123");
	ft_printf("my printf: %x\n", -42);
	printf("le printf: %x\n", -42);
	ft_printf("my printf: %X\n", -42);
	printf("le printf: %X\n", -42);
	return (1);
}
