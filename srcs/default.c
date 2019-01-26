/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbartol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:24:44 by flbartol          #+#    #+#             */
/*   Updated: 2019/01/24 18:31:10 by flbartol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	default_setting(t_flag *struc)
{
	if (struc->conv == 'd' || struc->conv == 'i' || struc->conv == 'u'
			|| struc->conv == 'o' || struc->conv == 'x' || struc->conv == 'X'
			&& (struc->prec == 0))
		struc->prec == 1;
	else if (struc->conv == 'f' && (struc->prec == 0))
		struc->prec == 6;
}
