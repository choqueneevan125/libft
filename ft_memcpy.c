/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 09:46:42 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/20 14:32:22 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_src;
	unsigned char	*ptr_dest;
	size_t			i;

	i = 0;
	ptr_src = (unsigned char *) src;
	ptr_dest = (unsigned char *) dest;
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
