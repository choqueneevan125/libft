/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 14:55:41 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/20 14:55:41 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "libft.h"

/*
Suite de tests unitaires pour les fonctions surlignées en jaune
*/

void	test_isalpha(void)
{
	printf("[TEST] ft_isalpha... ");
	assert(!!ft_isalpha('a') == !!isalpha('a'));
	assert(!!ft_isalpha('Z') == !!isalpha('Z'));
	assert(!!ft_isalpha('1') == !!isalpha('1'));
	assert(!!ft_isalpha(' ') == !!isalpha(' '));
	assert(!!ft_isalpha(128) == !!isalpha(128));
	printf("OK\n");
}

void	test_isdigit(void)
{
	printf("[TEST] ft_isdigit... ");
	assert(!!ft_isdigit('0') == !!isdigit('0'));
	assert(!!ft_isdigit('9') == !!isdigit('9'));
	assert(!!ft_isdigit('a') == !!isdigit('a'));
	assert(!!ft_isdigit(-1) == !!isdigit(-1));
	printf("OK\n");
}

void	test_isalnum(void)
{
	printf("[TEST] ft_isalnum... ");
	assert(!!ft_isalnum('a') == !!isalnum('a'));
	assert(!!ft_isalnum('8') == !!isalnum('8'));
	assert(!!ft_isalnum('!') == !!isalnum('!'));
	printf("OK\n");
}

void	test_isascii(void)
{
	printf("[TEST] ft_isascii... ");
	assert(!!ft_isascii(0) == !!isascii(0));
	assert(!!ft_isascii(127) == !!isascii(127));
	assert(!!ft_isascii(128) == !!isascii(128));
	assert(!!ft_isascii(-1) == !!isascii(-1));
	printf("OK\n");
}

void	test_isprint(void)
{
	printf("[TEST] ft_isprint... ");
	assert(!!ft_isprint(' ') == !!isprint(' '));
	assert(!!ft_isprint('~') == !!isprint('~'));
	assert(!!ft_isprint(31) == !!isprint(31));
	assert(!!ft_isprint(127) == !!isprint(127));
	printf("OK\n");
}

void	test_strlen(void)
{
	printf("[TEST] ft_strlen... ");
	assert(ft_strlen("") == strlen(""));
	assert(ft_strlen("Hello World!") == strlen("Hello World!"));
	assert(ft_strlen("42\0School") == strlen("42\0School"));
	printf("OK\n");
}

void	test_memset(void)
{
	printf("[TEST] ft_memset... ");
	char	buf1[20] = "1234567890";
	char	buf2[20] = "1234567890";

	ft_memset(buf1, 'A', 5);
	memset(buf2, 'A', 5);
	assert(memcmp(buf1, buf2, 20) == 0);
	ft_memset(buf1, 0, 10);
	memset(buf2, 0, 10);
	assert(memcmp(buf1, buf2, 20) == 0);
	printf("OK\n");
}

void	test_bzero(void)
{
	printf("[TEST] ft_bzero... ");
	char	buf1[20] = "abcdefghij";
	char	buf2[20] = "abcdefghij";

	ft_bzero(buf1, 5);
	bzero(buf2, 5);
	assert(memcmp(buf1, buf2, 20) == 0);
	printf("OK\n");
}

void	test_memcpy(void)
{
	printf("[TEST] ft_memcpy... ");
	char	src[20] = "Hello 42!";

	char	dst1[20] =
	{
		0
	};
	char	dst2[20] =
	{
		0
	};
	ft_memcpy(dst1, src, 9);
	memcpy(dst2, src, 9);
	assert(memcmp(dst1, dst2, 20) == 0);
	printf("OK\n");
}

void	test_memmove(void)
{
	printf("[TEST] ft_memmove... ");
	// Test avec chevauchement (overlap) : src avant dst
	char	str1[30] = "1234567890";
	char	str2[30] = "1234567890";

	ft_memmove(str1 + 2, str1, 5);
	memmove(str2 + 2, str2, 5);
	assert(memcmp(str1, str2, 30) == 0);
	// Test avec chevauchement : dst avant src
	char	str3[30] = "1234567890";
	char	str4[30] = "1234567890";

	ft_memmove(str3, str3 + 2, 5);
	memmove(str4, str4 + 2, 5);
	assert(memcmp(str3, str4, 30) == 0);
	printf("OK\n");
}

int	main(void)
{
	printf("=== DÉBUT DES TESTS LIBFT =\n\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	printf("\n= TOUS LES TESTS ONT RÉUSSI ! ===\n");
	return (0);
}
