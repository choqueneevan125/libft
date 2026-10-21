/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 13:31:19 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/21 13:54:10 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	c_char;

	i = 0;
	c_char = (unsigned char) c;
	while (s[i])
	{
		if (s[i] == c_char)
		{
			return ((char *) & s[i]);
		}
		i++;
	}
	if (s[i] == c_char)
	{
		return ((char *) & s[i]);
	}
	return (NULL);
}
