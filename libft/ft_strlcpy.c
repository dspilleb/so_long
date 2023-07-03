/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:20:13 by dan               #+#    #+#             */
/*   Updated: 2023/07/03 16:31:14 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;
	size_t	a;

	a = 0;
	while (src[a])
		a++;
	if (size <= 0)
		return (a);
	i = 0;
	while (src[i] && size - 1 > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (a);
}
