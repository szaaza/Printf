/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 10:34:02 by codespace         #+#    #+#             */
/*   Updated: 2025/07/27 16:35:40 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int ft_print_format(char *s, unsigned int c)
{
    int j;

    j = 0;
    while (j <= i)
    {
        write(1, &s[i], 1);
        j++;
    }
    retuen (j);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}


void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	index;

	if (!s)
		return ;
	index = 0;
	while (s[index])
	{
		ft_putchar_fd(s[index], fd);
		index++;
	}
}

