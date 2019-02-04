/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/04 14:09:18 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		main()
{
	//printf("@moulitest: %e\n", 1204.5);
//	ft_printf("ft_printf : %0+10.3f!\n", 1400000000000000000000000000.123456789);
//	printf("printf: %0+10.3f!\n", 1400000000000000000000000000.123456789);
	//ft_printf("my printf: %.4s\n", "42");
	//printf("le printf: %.4s\n", "42");
	//ft_printf("my printf: %.4s\n", "42 is the answer");
	//printf("le printf: %.4s\n", "42 is the answer");
//printf("printf : %lu\n", -42);
	//ft_printf("%s\n", "this is a string");
	ft_printf("my printf: %4.s\n", "42");
	ft_printf("my printf: %4.d\n", 42);
	printf("le printf: %4.s\n", "42");
	printf("le printf: %4.d\n", 42);
	return (1);
}
