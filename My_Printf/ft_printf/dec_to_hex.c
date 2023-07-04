/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dan <dan@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 18:27:30 by dan               #+#    #+#             */
/*   Updated: 2022/10/02 17:34:20 by dan              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long	int	len_hex(unsigned long long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		len++;
	while (nb != 0)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

char	*dec_to_hex_lowercase(unsigned long long nb)
{
	long int	i;
	char		*str;
	int			tmp;
	char		base[17];

	ft_memcpy(base, "0123456789abcdef", 17);
	i = len_hex(nb) - 1;
	str = malloc(len_hex(nb) + 1);
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (nb == 0)
		str[i] = base[0];
	while (nb != 0)
	{
		tmp = nb % 16;
		str[i] = base[tmp];
		nb /= 16;
		i--;
	}
	return (str);
}

char	*dec_to_hex_uppercase(unsigned long long nb)
{
	long int	i;
	char		*str;
	int			tmp;
	char		base[17];

	ft_memcpy(base, "0123456789ABCDEF", 17);
	i = len_hex(nb) - 1;
	str = malloc(len_hex(nb) + 1);
	if (!str)
		return (NULL);
	str[i + 1] = '\0';
	if (nb == 0)
		str[i] = base[0];
	while (nb != 0)
	{
		tmp = nb % 16;
		str[i] = base[tmp];
		nb /= 16;
		i--;
	}
	return (str);
}
