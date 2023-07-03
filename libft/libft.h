/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dspilleb <dspilleb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 20:44:41 by dan               #+#    #+#             */
/*   Updated: 2023/07/03 17:20:21 by dspilleb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlen(char const *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dest, char const *src, size_t size);

#endif
