/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 13:35:04 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/19 13:37:31 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	main(void)
{
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('4'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('a'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('Z'));
	printf("Fonction isalpha {res: %d}\n", ft_isalpha('{'));
	return (0);
}
