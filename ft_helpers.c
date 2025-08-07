/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <<sazanjan@student.42heilbronn    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:34:02 by codespace         #+#    #+#             */
/*   Updated: 2025/08/07 13:36:24 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

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

int	ft_u(unsigned int u, int *count)
{
	if (u >= 10)
		if (ft_u(u / 10, count) == -1)
			return (-1);
	if (ft_c((u % 10) + '0', count) == -1)
		return (-1);
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

int	ft_p(void *p, int *count)
{
	const char	*base;
	char		chars[30];
	int			i;
	uintptr_t	ptr;

	base = "0123456789abcdef";
	i = 0;
	ptr = (uintptr_t)p;
	if (ptr == 0)
		return (ft_s(PTRNULL, count));
	if (ft_s("0x", count) == -1)
		return (-1);
	while (ptr)
	{
		chars[i] = base[ptr % 16];
		i++;
		ptr /= 16;
	}
	while (i--)
		if (ft_c(chars[i], count) == -1)
			return (-1);
	return (0);
}
