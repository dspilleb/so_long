/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 17:29:36 by dan               #+#    #+#             */
/*   Updated: 2023/01/26 14:32:17 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	check_flag0(va_list ap, char c, int count)
{
	unsigned int	b;

	if (c == 'u')
	{
		b = va_arg(ap, int);
		ft_putunbr_fd (b, 1);
		if (b == 0)
			count++;
		while (b > 0)
		{
			b /= 10;
			count++;
		}
	}
	return (count);
}

int	check_flag1(va_list ap, char c, int count)
{
	int		b;

	if (c == 'd' || c == 'i')
	{
		b = va_arg(ap, int);
		ft_putnbr_fd (b, 1);
		if (b == -2147483648)
			return (count + 11);
		if (b <= 0)
		{
			count++;
			b *= -1;
		}
		while (b > 0)
		{
			b /= 10;
			count++;
		}
	}
	return (count);
}

int	check_flag2(va_list ap, char c, int count)
{
	char	*str;

	if (c == 'p')
	{
		str = dec_to_hex_lowercase(va_arg(ap, unsigned long long));
		if (str[0] == '0' && !(str[1]))
		{
			ft_putstr_fd("0x0", 1);
			free (str);
			return (count + 3);
		}
		write(1, "0x", 2);
		count += 2;
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
		free (str);
	}
	else if (c == 'x')
	{
		str = dec_to_hex_lowercase(va_arg(ap, unsigned int));
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
		free (str);
	}
	return (count);
}

int	check_flag3(va_list ap, char c, int count)
{
	char	a;
	char	*str;

	if (c == 'X')
	{
		str = dec_to_hex_uppercase(va_arg(ap, unsigned int));
		ft_putstr_fd(str, 1);
		count += ft_strlen(str);
		free (str);
	}
	else if (c == 'c')
	{
		a = va_arg(ap, int);
		write(1, &a, 1);
		count++;
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		count += 1;
	}
	return (count);
}

int	check_flag4(va_list ap, char c, int count)
{
	char	*str;

	if (c == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
		{
			ft_putstr_fd ("(null)", 1);
			count += 6;
			return (count);
		}
		ft_putstr_fd (str, 1);
		count += ft_strlen(str);
	}
	return (count);
}
