/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_atoi.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 16:00:00 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/20 16:38:59 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_to_int(char c)
{
	return (c - '0');
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	k;
	int	res;

	i = 0;
	k = 1;
	res = 0;
	while (nptr[i] >= 1 && nptr[i] <= 32)
	{
		i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			k *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (char_to_int(nptr[i]));
		i++;
	}
	return (res * k);
}
