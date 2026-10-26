/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strmapi.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 08:54:28 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/26 11:04:56 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	size_t	len;
	char	*res;

	i = 0;
	len = ft_strlen(s);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i] != 0)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
