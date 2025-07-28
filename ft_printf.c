/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:53:18 by codespace         #+#    #+#             */
/*   Updated: 2025/07/28 10:19:20 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
/*
#include "ft_printf.h"  
int ft_print_format(format, ...);
*/
int ft_printf(const char *start, ...)
{
	va_list args;
	int i;
	int total_len;
	int c;

	i = 0;
	total_len = 0;
	va_start(args, start);
	while (start[i])
	{
		if (start[i] == '%')
		{	
			if (start[i + 1] == '%')
			{
				write(1, &start[i], 1);
				total_len++;
				i++;
			}
			ft_printf_declaration(start[i + 1]);
			c = va_arg(args, unsigned int);
			total_len += ft_print_format(start[i + 1], c);
			i++;
		}
		else
		{
			write(1, &start[i], 1);
			total_len++;
		}
		i++;
	}
	va_end(args);
	return (total_len);
}

int main(int argc, char **argv)
{
	int sum1;

	sum1 = ft_printf("kjasdh");
	// printf("%d,.,.,%010.1d\n" , sum1, sum1);
	// sum1 = ff(4, 5, 'f', 6, 'o', 7, 'i', 8, 'k');
	printf("%c\n" , sum1);

	return (0);
}

// This function should handle different format specifiers
static int ft_printf_declaration(char format)
{
	if (format == '%'){	
		ft_putchar_fd(format, 1);
		return (1); // Placeholder for percent sign handling
	}
	else if (format == 'c')
		
	else if (format == 's')
		return (2); // Placeholder for string handling
	else if (format == 'd' || format == 'i')
		return (3); // Placeholder for integer handling
	else if (format == 'u')
		return (4); // Placeholder for unsigned integer handling
	else if (format == 'x' || format == 'X')
		return (5); // Placeholder for hexadecimal handling
	else
		return (0); // Unknown format specifier
}
