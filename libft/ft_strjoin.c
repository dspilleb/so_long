/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 20:11:12 by dan               #+#    #+#             */
/*   Updated: 2022/10/16 20:15:08 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		end_s1;
	size_t		end_s2;
	char		*str;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	end_s1 = ft_strlen(s1);
	end_s2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (end_s1 + end_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, end_s1 + 1);
	while (i < end_s2)
	{
		str[end_s1 + i] = s2[i];
		i++;
	}
	str[end_s1 + i] = '\0';
	return (str);
}
