/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 11:32:10 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/20 14:44:17 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;
	size_t			i;

	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	if (ptr_dest < ptr_src)
	{
		i = 0;
		while (i < n)
		{
			ptr_dest[i] = ptr_src[i];
			i++;
		}
	}
	else if (ptr_dest > ptr_src)
	{
		while (n > 0)
		{
			n--;
			ptr_dest[n] = ptr_src[n];
		}
	}
	return (dest);
}
