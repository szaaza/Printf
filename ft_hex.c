/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <sazanjan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:29:58 by sazanjan          #+#    #+#             */
/*   Updated: 2025/08/04 15:45:25 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lx_ux(unsigned int x, int *count, char mode)
{
	char		chars[30];
	const char	*base;
	int			i;

	i = 0;
	if (mode == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (x == 0)
		return (ft_c('0', count));
	while (x)
	{
		chars[i++] = base[x % 16];
		x /= 16;
	}
	while (--i >= 0)
	{
		if (ft_c(chars[i], count) == -1)
			return (-1);
	}
	return (0);
}
