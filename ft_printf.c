/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:53:18 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 15:43:44 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/*
int ft_printf(const char *format, ...)
{
    va_list args;
    int i;
    int total_len;
    
	total_len = 0;
	i = 0;
    va_start(args, format);
	while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            total_len += ft_printf_declaration(format[i + 1]);
            i++;
        }
        else
        {
            write(1, &format[i], 1);
            total_len++;
        }
        i++;
    }
    
    va_end(args);
    return (total_len);
}
*/

int ft_printf(const char *format, ...)
{
	va_list args;
	int i = 0;
	int char_count = 0;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			ft_format_dispatcher(format[i], &args, &char_count, &i);
		}
		else
		{
			write(1, &format[i], 1);
			char_count++;
		}
		i++;
	}
	va_end(args);
	return (char_count);
}



#include <stdarg.h>

static int	ft_format_dispatcher(char specifier, va_list *args, int *char_count, int *i)
{
	if (specifier == 'c')
		return (ft_c(va_arg(*args, int), char_count));
	else if (specifier == 's')
		return (ft_s(va_arg(*args, char *), char_count));
	else if (specifier == 'p')
		return (ft_p(va_arg(*args, size_t), char_count));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_d_i(va_arg(*args, int), char_count));
	else if (specifier == 'u')
		return (ft_u(va_arg(*args, unsigned int), char_count));
	else if (specifier == 'x')
		return (ft_lx_ux(va_arg(*args, unsigned int), char_count, 'x'));
	else if (specifier == 'X')
		return (ft_lx_ux(va_arg(*args, unsigned int), char_count, 'X'));
	else if (specifier == '%')
		return (ft_c('%', char_count));
	else
	{
		(*i)--;  // Rewind index because it wasn't a valid format
		return (-1); // Invalid specifier
	}
}

