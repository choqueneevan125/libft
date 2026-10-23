/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/23 08:16:09 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/23 11:55:31 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s1, char const *set)
{
	int	start;
	int	j;

	start = 0;
	while (s1[start])
	{
		j = 0;
		while (set[j] != s1[start] && set[j])
			j++;
		if (!set[j])
			return (start);
		start++;
	}
	return (start);
}

static size_t	get_len(char const *s1, char const *set)
{
	size_t	end;
	int		j;

	end = ft_strlen(s1);
	while (end > 0)
	{
		j = 0;
		while (set[j] && set[j] != s1[end - 1])
			j++;
		if (!set[j])
			break ;
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	size_t	len;
	char	*res;

	start = get_start(s1, set);
	len = get_len(s1, set) - start;
	res = ft_substr(s1, start, len);
	return (res);
}
