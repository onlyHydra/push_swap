/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiper <schiper@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:18:00 by schiper           #+#    #+#             */
/*   Updated: 2024/12/02 16:52:46 by schiper          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(FT_PRINTF_H)
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_strlen(const char *s);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_puthex(unsigned long num, const char *hex);
int	ft_putptr(void *ptr);
int	ft_printf(const char *format, ...);
#endif // FT_PRINTF_H
