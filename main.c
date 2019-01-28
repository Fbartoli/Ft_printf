/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/28 13:03:26 by flbartol         ###   ########.fr       */
=======
/*   Updated: 2019/01/28 15:16:11 by apsaint-         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main()
{
<<<<<<< HEAD
	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);
=======
	int c = 128;
	int *b = &c;
	ft_printf("my printf: %-15p\n", b);
	printf("le printf: %-15p\n", b);
	ft_printf("my printf: %-15X\n", *b);
	printf("le printf: %-15X\n", *b);
>>>>>>> master
	return (1);
}
