/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/03 20:38:03 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"

int		main()
{
	printf("@moulitest: %e\n", 1204.5);
	ft_printf("%0+10.3f!\n", 14.123456789);
	printf("%0+10.3f!\n", 14.123456789);
	return (1);
}
