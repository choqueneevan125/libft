/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 14:52:09 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/23 11:17:55 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	int		size_malloc;

	i = 0;
	size_malloc = 0;
	while (s[start + size_malloc] != 0 && i < len)
		size_malloc++;
	dest = malloc(sizeof(char) * (size_malloc + 1));
	if (!dest)
		return (NULL);
	while (s[start + i] != 0 && i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
