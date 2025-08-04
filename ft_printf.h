/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sazanjan <sazanjan@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 09:54:01 by codespace         #+#    #+#             */
/*   Updated: 2025/08/04 15:24:46 by sazanjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>

int	ft_printf(const char *format, ...);
int	ft_format_dispatcher(char specifier, va_list *args, int *count, int *i);

int	ft_c(char c, int *count);
int	ft_s(char *str, int *count);
int	ft_p(void *p, int *count);
int	ft_d_i(int n, int *count);
int	ft_u(unsigned int u, int *count);
int	ft_lx_ux(unsigned int x, int *count, char mode);

#endif
