/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:03:30 by dan               #+#    #+#             */
/*   Updated: 2023/01/26 14:33:11 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		count;
	int		i;
	va_list	ap;

	count = 0;
	i = -1;
	va_start(ap, s);
	while (s[++i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			count = check_flags(ap, s[i + 1], count);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
