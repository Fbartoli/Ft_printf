/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 18:04:02 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/28 18:04:07 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
	int c = 128;
	int *b = &c;
	ft_printf("my printf: %-15p\n", b);
	printf("le printf: %-15p\n", b);
	ft_printf("my printf: %-15X\n", *b);
	printf("le printf: %-15X\n", *b);
	return (1);
}
