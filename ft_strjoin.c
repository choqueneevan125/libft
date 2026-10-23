/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/23 07:41:04 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/23 08:12:08 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_size(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	return (len_s1 + len_s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	int		i;
	char	*res;
	int		temp;

	i = 0;
	temp = 0;
	size = get_size(s1, s2);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[temp])
	{
		res[i + temp] = s2[temp];
		temp++;
	}
	res[i + temp] = 0;
	return (res);
}
