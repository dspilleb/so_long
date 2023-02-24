/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 11:50:41 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 15:41:43 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_int(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

static char	*ft_itoa2(int n, char *str, int i)
{
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[i] = '\0';
	i--;
	while (n / 10 > 0)
	{
		str[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	str[i] = n % 10 + 48;
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = len_int(n);
	if (n == (-2147483648))
	{
		str = (char *)malloc(12);
		if (!str)
			return (NULL);
		ft_memcpy(str, "-2147483648", 12);
		return (str);
	}
	str = (char *)malloc(len_int(n) + 1);
	if (!str)
		return (NULL);
	str = ft_itoa2(n, str, i);
	return (str);
}
