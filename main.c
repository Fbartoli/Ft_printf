/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/31 14:02:45 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		main()
{
	int c = 128;
	int *b = &c;
	ft_printf("my printf: %-15p\n", "123");
	printf("le printf: %-15p\n", "123");
	ft_printf("my printf: %#X\n", b);
	printf("le printf: %#X\n", b);
	ft_printf("my printf: %-15p\n", b);
	printf("le printf: %-15p\n", b);
	ft_printf("my printf: %-15X\n", *b);
	printf("le printf: %-15X\n", *b);
	return (1);
}
