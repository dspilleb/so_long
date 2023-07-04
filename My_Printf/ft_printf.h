/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:29:08 by dan               #+#    #+#             */
/*   Updated: 2023/01/26 14:28:39 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char const *str);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*dec_to_hex_lowercase(unsigned long long nb);
long	int	len_hex(unsigned long long nb);
char	*dec_to_hex_uppercase(unsigned long long nb);
int		check_flags(va_list ap, char c, int count);
int		check_flag3(va_list ap, char c, int count);
int		check_flag2(va_list ap, char c, int count);
int		check_flag1(va_list ap, char c, int count);
int		check_flag4(va_list ap, char c, int count);
int		check_flag0(va_list ap, char c, int count);
void	ft_putunbr_fd(unsigned int n, int fd);

#endif