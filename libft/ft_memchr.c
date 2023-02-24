/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 21:04:17 by dan               #+#    #+#             */
/*   Updated: 2022/10/24 12:27:20 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	const char	*str;
	const char	f = c;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if (*(str + i) == f)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
