/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 16:01:44 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/22 08:41:27 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c_char;

	i = ft_strlen(s);
	c_char = (unsigned char) c;
	while (i >= 0)
	{
		if (s[i] == c_char)
		{
			return ((char *) & s[i]);
		}
		i--;
	}
	return (NULL);
}
