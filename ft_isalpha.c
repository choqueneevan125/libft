/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_isalpha.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: e <evanchoq@student.42lehavre.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:09:27 by e                #+#    #+#              */
/*   Updated: 2026/10/19 13:25:20 by e               ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}

int	main(void)
{
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('4'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('a'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('Z'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('{'));
	return (0);
}
