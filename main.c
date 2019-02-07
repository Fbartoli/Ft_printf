/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@42.student.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/07 11:23:18 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
# include <wchar.h>
int		main()
{
	ft_printf("My printf: %.4S\n", L"我是一只猫。");
	printf("Le printf: %.4S\n", L"我是一只猫。");
	ft_printf("My printf: %15.4S\n", L"我是一只猫。");
	printf("Le printf: %15.4S\n", L"我是一只猫。");
	return (1);
}
