/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:24:05 by dan               #+#    #+#             */
/*   Updated: 2022/10/02 10:14:50 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n < -2147483647)
	{
		write(fd, "-2147483648", 11);
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd((n + '0'), fd);
	}
	else if (n < 0 && n > -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(n *(-1), fd);
	}
	else if (n > -2147483648)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
