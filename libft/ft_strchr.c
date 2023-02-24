/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:25:56 by dan               #+#    #+#             */
/*   Updated: 2022/10/24 12:27:03 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	f = c;

	i = -1;
	while (s[++i])
		if (s[i] == f)
			return ((char *)&s[i]);
	if (s[i] == f)
		return ((char *)&s[i]);
	return (NULL);
}
