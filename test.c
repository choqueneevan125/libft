/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 14:55:41 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/22 08:35:42 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "libft.h"

void	run_test(const void *s, int c, size_t n, const char *test_name);

void	test_strchr(void)
{
	printf("[TEST] ft_strchr... ");
	char	*str = "Hello, 42LeHavre!";

	// Test 1 : Recherche d'un caractère présent au milieu
	assert(ft_strchr(str, 'o') == strchr(str, 'o'));
	// Test 2 : Recherche du premier caractère
	assert(ft_strchr(str, 'H') == strchr(str, 'H'));
	// Test 3 : Recherche du dernier caractère avant le '\0'
	assert(ft_strchr(str, '!') == strchr(str, '!'));
	// Test 4 : Recherche du caractère nul '\0'
	assert(ft_strchr(str, '\0') == strchr(str, '\0'));
	// Test 5 : Recherche d'un caractère absent
	assert(ft_strchr(str, 'z') == strchr(str, 'z'));
	// Test 6 : Test du cast en unsigned char (ex: dépassement avec int)
	// 'o' correspond à 111, 111 + 256 = 367 -> (unsigned char)367 == 111 ('o')
	assert(ft_strchr(str, 'o' + 256) == strchr(str, 'o' + 256));
	printf("OK\n");
}

void	test_strrchr(void)
{
	printf("[TEST] ft_strrchr... ");
	char	*str = "Hello, 42LeHavre!";

	// Test 1 : Recherche d'un caractère présent plusieurs fois (doit trouver le dernier 'e')
	assert(ft_strrchr(str, 'e') == strrchr(str, 'e'));
	// Test 2 : Recherche du premier caractère s'il est unique
	assert(ft_strrchr(str, 'H') == strrchr(str, 'H'));
	// Test 3 : Recherche du dernier caractère avant '\0'
	assert(ft_strrchr(str, '!') == strrchr(str, '!'));
	// Test 4 : Recherche du caractère nul '\0'
	assert(ft_strrchr(str, '\0') == strrchr(str, '\0'));
	// Test 5 : Recherche d'un caractère absent
	assert(ft_strrchr(str, 'z') == strrchr(str, 'z'));
	// Test 6 : Cast en unsigned char ('e' + 256)
	assert(ft_strrchr(str, 'e' + 256) == strrchr(str, 'e' + 256));
	// Test 7 : Chaîne vide
	assert(ft_strrchr("", 'a') == strrchr("", 'a'));
	assert(ft_strrchr("", '\0') == strrchr("", '\0'));
	printf("OK\n");
}

void	test_tolower_uplower(void)
{
	printf("%c\n", ft_tolower('C'));
	printf("%c\n", ft_tolower('d'));
	printf("%c\n", ft_toupper('B'));
	printf("%c\n", ft_toupper('a'));
}

void	test_1(void)
{
	printf("=== DEBUT DES TESTS FT_MEMCHR ===\n\n");
	// Test 1 : Recherche basique d'un caractère présent
	char	str1[] = "Hello World!";

	run_test(str1, 'W', 12, "Test 1: Caractere présent");
	// Test 2 : Caractère absent
	run_test(str1, 'z', 12, "Test 2: Caractere absent");
	// Test 3 : Recherche du caractère null `\0`
	run_test(str1, '\0', 13, "Test 3: Recherche de \\0");
	// Test 4 : Caractère présent mais au-delà de la taille `n`
	run_test(str1, 'W', 5, "Test 4: Caractere hors de la limite n");
	// Test 5 : Recherche dans un tableau d'entiers / octets non-ASCII
	unsigned char	bytes[] =
	{
		0x01, 0x02, 0xFF, 0x04, 0x05
	};
	run_test(bytes, 0xFF, 5, "Test 5: Tableau d'octets / 0xFF");
	// Test 6 : Conversion de int à unsigned char pour le chercheur
	char	str2[] = "abcde";

	run_test(str2, 'c' + 256, 5, "Test 6: Overflow du paramètre 'c' (int -> unsigned char)");
	printf("\n=== FIN DES TESTS ===\n");
}

void	run_test(const void *s, int c, size_t n, const char *test_name)
{
	void	*res_ft;
	void	*res_std;

	res_ft = ft_memchr(s, c, n);
	res_std = memchr(s, c, n);
	if (res_ft == res_std)
		printf("[OK] %s\n", test_name);
	else
	{
		printf("[KO] %s\n", test_name);
		printf("   -> Attendu : %p\n", res_std);
		printf("   -> Obtenu  : %p\n", res_ft);
	}
}

void	test_memcmp(void)
{
	printf("%d\n", ft_memcmp("Hello", "Hello", 5));
	printf("%d\n", ft_memcmp("olleh", "Hello", 5));
	printf("%d\n", ft_memcmp("test", "test", 3));
	printf("%d\n", ft_memcmp("test", "123", 3));
	printf("%d\n", ft_memcmp("", "Hello", 5));
}

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
	printf("%d\n", ft_atoi("      \n  -5"));
	test_memcmp();
	test_1();
	test_tolower_uplower();
	test_strchr();
	test_strrchr();
	return (0);
}
