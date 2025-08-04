/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <sazanjan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:53:18 by codespace         #+#    #+#             */
/*   Updated: 2025/08/04 15:46:46 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format_loop(const char *format, va_list *args)
{
	int	i;
	int	count;
	int	ret;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ret = ft_format_dispatcher(format[i], args, &count, &i);
			if (ret == -1)
				return (-1);
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_format_dispatcher(char specifier, va_list *args, int *count, int *i)
{
	if (specifier == 'c')
		return (ft_c(va_arg(*args, int), count));
	else if (specifier == 's')
		return (ft_s(va_arg(*args, char *), count));
	else if (specifier == 'p')
		return (ft_p(va_arg(*args,  void *), count));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_d_i(va_arg(*args, int), count));
	else if (specifier == 'u')
		return (ft_u(va_arg(*args, unsigned int), count));
	else if (specifier == 'x')
		return (ft_lx_ux(va_arg(*args, unsigned int), count, 'x'));
	else if (specifier == 'X')
		return (ft_lx_ux(va_arg(*args, unsigned int), count, 'X'));
	else if (specifier == '%')
		return (ft_c('%', count));
	else
	{
		(*i)--;
		return (-1);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;

	va_start(args, format);
	result = ft_format_loop(format, &args);
	va_end(args);
	return (result);
}
