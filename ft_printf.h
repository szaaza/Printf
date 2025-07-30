/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:54:01 by codespace         #+#    #+#             */
/*   Updated: 2025/07/30 15:50:53 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

// Main
int	ft_printf(const char *format, ...);
int	ft_format_dispatcher(char specifier, va_list *args, int *count, int *i);

// Helpers
int	ft_c(char c, int *count);
int	ft_s(char *str, int *count);
int	ft_p(size_t p, int *count);
int	ft_d_i(int n, int *count);
int	ft_u(unsigned int u, int *count);
int	ft_lx_ux(unsigned int x, int *count, char mode);

#endif
