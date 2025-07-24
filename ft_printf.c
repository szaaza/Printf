/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:53:18 by codespace         #+#    #+#             */
/*   Updated: 2025/07/24 13:38:36 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

// int ft_printf(const char *format, ...)
// {
//     int return_value;
    
//     return_value = 0;
// }
// int func(char *count, int y, cahr t, ...)
// {
//     va_start (args, t);
// while
//     s = va_arg(args , int);
//     s = va_arg(args , char);
// }

int ff(int count, ...)
{
    int i;
    int s;
    char c;
    va_list args;

    i = 0;
    s = 0;
    va_start (args, count);
    while(i < count)
    {
        s = va_arg(args , int);
        c = (char)va_arg(args , int);
        i++;       
    }

    va_end (args);
    return (s);
}
int main(int argc, char **argv)
{
    int sum1;

    // sum1 = sum(2, 4, 6);
    // printf("%d\n" , sum1);
    // sum1 = sum(4,5,6,7,8);
    // printf("%d\n" , sum1);

    sum1 = ff(2, 4, 'c', 6, 't');
    printf("%d\n" , sum1);
    sum1 = ff(4, 5, 'f', 6, 'o', 7, 'i', 8, 'k');
    printf("%d\n" , sum1);

    return (0);
}