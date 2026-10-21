/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strncmp.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/21 17:35:36 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/21 17:54:49 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_un;
	unsigned char	*s2_un;
	size_t			i;

	i = 0;
	s1_un = (unsigned char *) s1;
	s2_un = (unsigned char *) s2;
	while (i < n)
	{
		if (s1_un[i] != s2_un[i])
		{
			return (s1_un[i] - s2_un[i]);
		}
		if (s1_un[i] == 0)
		{
			break ;
		}
		i++;
	}
	return (0);
}
