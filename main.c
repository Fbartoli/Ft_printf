/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2019/01/31 12:58:43 by apsaint-         ###   ########.fr       */
=======
/*   Updated: 2019/01/28 16:16:07 by apsaint-         ###   ########.fr       */
/*   Updated: 2019/01/28 13:03:26 by flbartol         ###   ########.fr       */
/*   Updated: 2019/01/28 15:16:11 by apsaint-         ###   ########.fr       */
>>>>>>> 4d6cd91235c9a655886dc1b8dedc2fa5bf39e974
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		main()
{
	int c = 128;
	int *b = &c;
<<<<<<< HEAD
	ft_printf("my printf: %-15p\n", "123");
	printf("le printf: %-15p\n", "123");
	ft_printf("my printf: %#X\n", b);
	printf("le printf: %#X\n", b);
=======
	ft_printf("my printf: %-15p\n", b);
	printf("le printf: %-15p\n", b);
	ft_printf("my printf: %-15X\n", *b);
	printf("le printf: %-15X\n", *b);
>>>>>>> 4d6cd91235c9a655886dc1b8dedc2fa5bf39e974
	return (1);
}
