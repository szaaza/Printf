/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <sazanjan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:34:02 by codespace         #+#    #+#             */
/*   Updated: 2025/07/31 11:58:05 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

#include "ft_printf.h"

int	ft_c(char c, int *count)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	(*count)++;
	return (0);
}

int	ft_s(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
	{
		if (ft_c(str[i], count) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_d_i(int n, int *count)
{
	if (n == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		*count += 11;
		return (0);
	}
	if (n < 0)
	{
		if (ft_c('-', count) == -1)
			return (-1);
		n = -n;
	}
	if (n > 9)
		if (ft_d_i(n / 10, count) == -1)
			return (-1);
	if (ft_c((n % 10) + '0', count) == -1)
		return (-1);
	return (0);
}

int	ft_u(unsigned int u, int *count)
{
	if (u >= 10)
		if (ft_u(u / 10, count) == -1)
			return (-1);
	if (ft_c((u % 10) + '0', count) == -1)
		return (-1);
	return (0);
}

int	ft_p(size_t p, int *count)
{
	char		chars[30];
	const char	*base;
	int			i;

	base = "0123456789abcdef";
	i = 0;
	if (ft_s("0x", count) == -1)
		return (-1);
	if (p == 0)
		return (ft_c('0', count));
	while (p)
	{
		chars[i++] = base[p % 16];
		p /= 16;
	}
	while (--i >= 0)
	{
		if (ft_c(chars[i], count) == -1)
			return (-1);
	}
	return (0);
}
