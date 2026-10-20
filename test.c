/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 13:35:04 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/20 10:15:44 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>
#include <string.h>

void	test_memcpy(void)
{
	char	dest[sizeof("Hello, World")];

	ft_memcpy(dest, "Hello, World", ft_strlen("Hello, World"));
	dest[ft_strlen("Hello, World")] = '\0';
	printf("%s\n", dest);
}

void	test_memset(void)
{
	int	test[4];

	ft_memset(test, 'c', sizeof(test));
	for (int i = 0; i < 4; i++)
	{
		printf("%c\n", test[i]);
	}
}

void	test_bzero(void)
{
	int	i[5];

	ft_bzero(i, sizeof(i));
	for (int j = 0; j < 5; j++)
	{
		printf("%d\n", i[j]);
	}
}

int	main(void)
{
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('4'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('a'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('Z'));
	printf("Fonction isalpha {res: %d}\n\n", ft_isalpha('{'));
	printf("Fonction isalpha {res: %d}\n", ft_isdigit('4'));
	printf("Fonction isalpha {res: %d}\n", ft_isdigit('a'));
	printf("Fonction isalpha {res: %d}\n", ft_isdigit('Z'));
	printf("Fonction isalpha {res: %d}\n\n", ft_isdigit('{'));
	printf("Fonction isalpha {res: %d}\n", ft_isalnum('4'));
	printf("Fonction isalpha {res: %d}\n", ft_isalnum('a'));
	printf("Fonction isalpha {res: %d}\n", ft_isalnum('Z'));
	printf("Fonction isalpha {res: %d}\n\n", ft_isalnum('{'));
	printf("Fonction isalpha {res: %d}\n", ft_isprint('4'));
	printf("Fonction isalpha {res: %d}\n", ft_isprint('a'));
	printf("Fonction isalpha {res: %d}\n", ft_isprint('{'));
	printf("Fonction isalpha {res: %d}\n\n", ft_isprint('\n'));
	printf("Le nombre de charactere dans ce texte 'Hello, World' : %ld charactere\n", ft_strlen("Hello, World"));
	test_memset();
	test_bzero();
	test_memcpy();
	return (0);
}
