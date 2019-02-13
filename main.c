/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <flbartol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 10:18:40 by apsaint-          #+#    #+#             */
/*   Updated: 2019/02/13 20:28:17 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
//# include <wchar.h>
# include <locale.h>
int		main()
{
	double		nb;
	nb = 0;

	ft_printf("test basique:\n\n\n");



 	printf("%d\n", ft_printf("space:% f\n", nb));
  	printf("%d   \n", printf("space:% f\n", nb));
    printf("%d   \n", ft_printf("plus:%+f\n", nb));
    printf("%d   \n", printf("plus:%+f\n", nb));
    printf("%d   \n", ft_printf("hash:%#f\n", nb));
    printf("%d   \n", printf("hash:%#f\n", nb));
    printf("%d   \n", ft_printf("precision:%.2f\n", nb));
    printf("%d   \n", printf("precision:%.2f\n", nb));
    printf("%d   \n", ft_printf("big prec:%.14f\n", nb));
    printf("%d   \n", printf("big prec:%.14f\n", nb));
	printf("%d   \n", ft_printf("big prec:%f\n", 1.42));
    printf("%d   \n", printf("big prec:%f\n", 1.42));
    printf("%d   \n", ft_printf("precision + hash:%#.0f\n", nb));
    printf("%d   \n", printf("precision + hash:%#.0f\n", nb));
    printf("%d   \n", ft_printf("space + prec:% .5f\n", nb));
    printf("%d   \n", printf("space + prec:% .5f\n", nb));
    printf("%d   \n", ft_printf("space + prec + hash:%# .0f\n", nb));
    printf("%d   \n", printf("space + prec + hash:%# .0f\n", nb));
    printf("%d   \n", ft_printf("space + prec + hash:% #.0f\n", nb));
    printf("%d   \n", printf("space + prec + hash:% #.0f\n", nb));
    printf("%d   \n", ft_printf("Plus + prec / grande:%+.5f\n", nb));
    printf("%d   \n", printf("Plus + prec / grande:%+.5f\n", nb));
   	printf("%d   \n", ft_printf("Plus + prec / petite:%+.0f\n", nb));
	printf("%d   \n", printf("Plus + prec / petite:%+.0f\n", nb));
    printf("%d   \n", ft_printf("Plus + prec + hash:%#+.0f\n", nb));
    printf("%d   \n", printf("Plus + prec + hash:%#+.0f\n", nb));
	printf("%d   \n", ft_printf("Prec + 0:%0.5f\n", nb));
    printf("%d   \n", printf("Prec + 0:%0.5f\n", nb));
    printf("%d   \n", ft_printf("Prec + minus:%-.5f\n", nb));
    printf("%d   \n", printf("Prec + minus:%-.5f\n", nb));
    printf("%d   \n", ft_printf("size:%5f\n", nb));
    printf("%d   \n", printf("size:%5f\n", nb));
    printf("%d   \n", ft_printf("size + space:% 5f\n", nb));
    printf("%d   \n", printf("size + space:% 5f\n", nb));
    printf("%d   \n", ft_printf("size + plus:%+5f\n", nb));
    printf("%d   \n", printf("size + plus:%+5f\n", nb));
    printf("%d   \n", ft_printf("size + space:%# 5f\n", nb));
    printf("%d   \n", printf("size + space:%# 5f\n", nb));
    printf("%d   \n", ft_printf("size + plus:%#+5f\n", nb));
   	printf("%d   \n", printf("size + plus:%#+5f\n", nb));
    printf("%d   \n", ft_printf("size + minus:%-5f\n", nb));
    printf("%d   \n", printf("size + minus:%-5f\n", nb));
    printf("%d   \n", ft_printf("size + 0:%05f\n", nb));
    printf("%d   \n", printf("size + 0:%05f\n", nb));
    printf("%d   \n", ft_printf("size + 0 + plus:%+05f\n", nb));
    printf("%d   \n", printf("size + 0 + plus:%+05f\n", nb));
    printf("%d   \n", ft_printf("size + 0 + plus:%0+5f\n", nb));
    printf("%d   \n", printf("size + 0 + plus:%0+5f\n", nb));
    printf("%d   \n", ft_printf("size + 0 + prec:%05.3f\n", nb));
    printf("%d   \n", printf("size + 0 + prec:%05.3f\n", nb));
    printf("%d   \n", ft_printf("size + 0 + prec + hash:%0#5.0f\n", nb));
    printf("%d   \n", printf("size + 0 + prec + hash:%0#5.0f\n", nb));
    printf("%d   \n", ft_printf("size + minus + prec:%-5.3f\n", nb));
    printf("%d   \n", printf("size + minus + prec:%-5.3f\n", nb));
    printf("%d   \n", ft_printf("size + minus + prec + hash:%-#5.0f\n", nb));
    printf("%d   \n", printf("size + minus + prec + hash:%-#5.0f\n", nb));
    printf("%d   \n", ft_printf("size + plus + 0 + prec:%+05.3f\n", nb));
    printf("%d   \n", printf("size + plus + 0 + prec:%+05.3f\n", nb));
    printf("%d   \n", ft_printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb));
    printf("%d   \n", printf("size + plus + 0 + prec + hash:%0+#5.0f\n", nb));
    printf("%d   \n", ft_printf("size + espace + zero + prec:%0 5.3f\n", nb));
    printf("%d   \n", printf("size + espace + zero + prec:%0 5.3f\n", nb));
    printf("%d   \n", ft_printf("size + espace + zero + prec:% 05.3f\n", nb));
    printf("%d   \n", printf("size + espace + zero + prec:% 05.3f\n", nb));
    printf("%d   \n", ft_printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb));
    printf("%d   \n", printf("size + espace + zero + prec + hash:%#0 5.0f\n", nb));
    printf("%d   \n", ft_printf("size + minus + plus + prec:%-+5.3f\n", nb));
    printf("%d   \n", printf("size + minus + plus + prec:%-+5.3f\n", nb));
    printf("%d   \n", ft_printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb));
    printf("%d   \n", printf("size + minus + plus + prec + hash:%-#+5.0f\n", nb));
	return (1);
}
