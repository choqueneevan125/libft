/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 07:52:05 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/26 08:34:08 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len_number(int nb)
{
	int		res;
	long	n;

	res = 0;
	n = (long) nb;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	long	nb;

	len = get_len_number(n);
	res = malloc(sizeof(char) * (len + 1));
	nb = (long) n;
	if (!res)
		return (NULL);
	res[len] = 0;
	if (nb == 0)
		res[0] = '0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		len--;
		res[len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (res);
}
