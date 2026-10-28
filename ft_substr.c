/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 14:52:09 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/28 11:46:44 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size_malloc;
	char	*dest;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	size_malloc = 0;
	while (size_malloc < len && s[start + size_malloc] != '\0')
		size_malloc++;
	dest = malloc(sizeof(char) * (size_malloc + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size_malloc)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
