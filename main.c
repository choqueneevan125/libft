/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 13:35:04 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/19 14:06:32 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <ctype.h>

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
	return (0);
}
