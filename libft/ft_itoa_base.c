/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 18:16:34 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/11 18:54:39 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int num, int base) 
{ 
	static char Representation[]= "0123456789ABCDEF";
	static char *buffer; 
	int len;
	long num_long;
	
	
	num_long = num;
	len = ft_nbrlen(num_long);
	if (!(buffer = (char *)(malloc(len + 1))))
		return (NULL);
	//if (num_long < 0)
//	{
//		buffer[0] = '-';
//		num_long *= -1;
//	}
	*(buffer + len) = '\0';
	len -= 2;
	while (num != 0)
	{ 
		buffer[len--] = Representation[num%base]; 
		num /= base; 
	} 
	return(buffer); 
}
