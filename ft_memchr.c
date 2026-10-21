/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 11:05:26 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/21 12:03:50 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	*res;
	unsigned char	c_char;

	i = 0;
	ptr = (unsigned char *) s;
	c_char = (unsigned char) c;
	while (i < n)
	{
		if (ptr[i] == c_char)
		{
			return (res = &ptr[i]);
		}
		i++;
	}
	return (NULL);
}
