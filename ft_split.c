/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/23 12:56:09 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/23 16:36:32 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_word_len(char const *s, char c)
{
	int	start;

	start = 0;
	while (s[start] && s[start] != c)
	{
		start++;
	}
	return (start);
}

static int	count_split(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	*free_all(char **free_str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(free_str[i]);
		i++;
	}
	free(free_str);
	return (NULL);
}

static char	*extract_word(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = get_word_len(s, c);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;
	int		i;
	int		j;

	count = count_split(s, c);
	res = malloc(sizeof(*res) * (count + 1));
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] && s[j] == c)
			j++;
		if (s[j])
		{
			res[i] = extract_word(&s[j], c);
			if (!res[i])
				return (free_all(res, i));
			j += get_word_len(&s[j], c);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
