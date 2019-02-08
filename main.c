/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 13:34:51 by flbartol          #+#    #+#             */
/*   Updated: 2019/02/08 10:58:40 by apsaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/ft_printf.h"
# include <wchar.h>
int		main()
{
	//ft_printf("My printf: %15.4S\n", L"我是一只猫。");
	ft_printf("My printf: %-10b\n", 2);
	ft_printf("My printf: %-10b\n", 300);
	//ft_printf("Le printf: {%05.S}", L"42 c est cool");
	return (1);
}
