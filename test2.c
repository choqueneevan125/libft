/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test2.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: evanchoq <evanchoq@student.42lehavre.fr>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/22 09:21:11 by evanchoq         #+#    #+#              */
/*   Updated: 2026/10/22 09:21:11 by evanchoq        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

/* Macros pour un affichage couleur des résultats */
#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define RESET "\033[0m"

static int	g_success = 0;
static int	g_failure = 0;

void	check_int(const char *func_name, int real, int ft)
{
	/* Pour les fonctions de classification (isalpha, etc.), la libc renvoie
	un entier non nul si vrai (pas forcément 1). On normalise à (val != 0). */
	int	is_char_func = (strcmp(func_name, "ft_isalpha") == 0 ||
		strcmp(func_name, "ft_isdigit") == 0 ||
	strcmp(func_name, "ft_isalnum") == 0 ||
	strcmp(func_name, "ft_isascii") == 0 ||
	strcmp(func_name, "ft_isprint") == 0);
	int	pass = is_char_func ? ((real != 0) == (ft != 0)) : (real == ft);

	if (pass)
	{
		printf("  [%sOK%s] %s (libc: %d | ft: %d)\n", GREEN, RESET, func_name, real, ft);
		g_success++;
	}
	else
	{
		printf("  [%sKO%s] %s (libc: %d | ft: %d)\n", RED, RESET, func_name, real, ft);
		g_failure++;
	}
}

void	check_str(const char *func_name, const char *real, const char *ft)
{
	if ((real == NULL && ft == NULL) || (real && ft && strcmp(real, ft) == 0))
	{
		printf("  [%sOK%s] %s (Résultat: \"%s\")\n", GREEN, RESET, func_name, ft ? ft : "NULL");
		g_success++;
	}
	else
	{
		printf("  [%sKO%s] %s (libc: \"%s\" | ft: \"%s\")\n", RED, RESET, func_name,
			real ? real : "NULL", ft ? ft : "NULL");
		g_failure++;
	}
}

void	check_mem(const char *func_name, const void *real, const void *ft, size_t size)
{
	if (memcmp(real, ft, size) == 0)
	{
		printf("  [%sOK%s] %s (Les zones mémoire correspondent)\n", GREEN, RESET, func_name);
		g_success++;
	}
	else
	{
		printf("  [%sKO%s] %s (Différence détectée dans le buffer)\n", RED, RESET, func_name);
		g_failure++;
	}
}

/* ------------------------------------------------------------------------- */
/*                                   TESTS                                   */
/* ------------------------------------------------------------------------- */

void	test_character_checks(void)
{
	printf(YELLOW "\n--- 1. Tests Caractères (isalpha, isdigit, isalnum, isascii, isprint) ---\n" RESET);
	int	test_chars[] =
	{
		'a', 'Z', '5', ' ', '\t', 127, 200, -1, 0
	};
	int	n = sizeof(test_chars) / sizeof(test_chars[0]);

	for (int i = 0; i < n; i++)
	{
		int	c = test_chars[i];

		check_int("ft_isalpha", isalpha(c), ft_isalpha(c));
		check_int("ft_isdigit", isdigit(c), ft_isdigit(c));
		check_int("ft_isalnum", isalnum(c), ft_isalnum(c));
		check_int("ft_isascii", isascii(c), ft_isascii(c));
		check_int("ft_isprint", isprint(c), ft_isprint(c));
	}
}

void	test_casing_conversions(void)
{
	printf(YELLOW "\n--- 2. Tests Conversions (toupper, tolower) ---\n" RESET);
	int	test_chars[] =
	{
		'a', 'Z', '5', '@', 0
	};
	int	n = sizeof(test_chars) / sizeof(test_chars[0]);

	for (int i = 0; i < n; i++)
	{
		int	c = test_chars[i];

		check_int("ft_toupper", toupper(c), ft_toupper(c));
		check_int("ft_tolower", tolower(c), ft_tolower(c));
	}
}

void	test_string_length_and_conv(void)
{
	printf(YELLOW "\n--- 3. Tests Chaînes & Nombres (strlen, atoi) ---\n" RESET);
	/* strlen */
	check_int("ft_strlen (\"Hello\")", strlen("Hello"), ft_strlen("Hello"));
	check_int("ft_strlen (\"\")", strlen(""), ft_strlen(""));
	/* atoi */
	check_int("ft_atoi (\"42\")", atoi("42"), ft_atoi("42"));
	check_int("ft_atoi (\"  -1234ab56\")", atoi("  -1234ab56"), ft_atoi("  -1234ab56"));
	check_int("ft_atoi (\"+2147483647\")", atoi("+2147483647"), ft_atoi("+2147483647"));
	check_int("ft_atoi (\"-2147483648\")", atoi("-2147483648"), ft_atoi("-2147483648"));
}

void	test_string_search_and_cmp(void)
{
	printf(YELLOW "\n--- 4. Tests Recherche/Comparaison (strchr, strrchr, strncmp) ---\n" RESET);
	const char	*str = "Hello 42 School!";
	/* strchr / strrchr */

	check_str("ft_strchr ('o')", strchr(str, 'o'), ft_strchr(str, 'o'));
	check_str("ft_strchr ('\\0')", strchr(str, '\0'), ft_strchr(str, '\0'));
	check_str("ft_strchr ('z')", strchr(str, 'z'), ft_strchr(str, 'z'));
	check_str("ft_strrchr ('o')", strrchr(str, 'o'), ft_strrchr(str, 'o'));
	check_str("ft_strrchr ('\\0')", strrchr(str, '\0'), ft_strrchr(str, '\0'));
	/* strncmp */
	check_int("ft_strncmp (\"abc\", \"abc\", 3)", strncmp("abc", "abc", 3), ft_strncmp("abc", "abc", 3));
	check_int("ft_strncmp (\"abcd\", \"abce\", 3)", strncmp("abcd", "abce", 3), ft_strncmp("abcd", "abce", 3));
	check_int("ft_strncmp (\"abcd\", \"abce\", 4)", strncmp("abcd", "abce", 4), ft_strncmp("abcd", "abce", 4));
}

void	test_memory_modifications(void)
{
	printf(YELLOW "\n--- 5. Tests Mémoire Brut (memset, bzero, memcpy, memmove) ---\n" RESET);
	char	buf_real[20];
	char	buf_ft[20];
	/* memset */

	memset(buf_real, 'A', 15);
	ft_memset(buf_ft, 'A', 15);
	check_mem("ft_memset", buf_real, buf_ft, 15);
	/* bzero */
	bzero(buf_real, 10);
	ft_bzero(buf_ft, 10);
	check_mem("ft_bzero", buf_real, buf_ft, 15);
	/* memcpy */
	const char	*src = "42 Le Havre";

	memcpy(buf_real, src, 11);
	ft_memcpy(buf_ft, src, 11);
	check_mem("ft_memcpy", buf_real, buf_ft, 11);
	/* memmove (chevauchement / overlap) */
	char	move_real[] = "1234567890";
	char	move_ft[] = "1234567890";

	memmove(move_real + 2, move_real, 5);
	ft_memmove(move_ft + 2, move_ft, 5);
	check_mem("ft_memmove (overlap)", move_real, move_ft, 10);
}

void	test_memory_search_and_cmp(void)
{
	printf(YELLOW "\n--- 6. Tests Recherche/Comparaison Mémoire (memchr, memcmp) ---\n" RESET);
	const char	data[] = "abcdef\0ghijkl";
	/* memchr */
	void	*p1 = memchr(data, 'g', 12);
	void	*p2 = ft_memchr(data, 'g', 12);

	check_int("ft_memchr ('g' après '\\0')", p1 == p2, 1);
	/* memcmp */
	check_int("ft_memcmp (égaux)", memcmp("abc", "abc", 3), ft_memcmp("abc", "abc", 3));
	check_int("ft_memcmp (différents)", memcmp("abc", "abd", 3), ft_memcmp("abc", "abd", 3));
}

void	test_allocation_functions(void)
{
	printf(YELLOW "\n--- 7. Tests Allocation Dynamique (calloc, strdup) ---\n" RESET);
	/* calloc */
	int	*r_arr = (int *) calloc(5, sizeof(int));
	int	*f_arr = (int *) ft_calloc(5, sizeof(int));

	if (r_arr && f_arr)
		check_mem("ft_calloc (5 int à zero)", r_arr, f_arr, 5 * sizeof(int));
	free(r_arr);
	free(f_arr);
	/* strdup */
	const char	*s = "String dupliquee !";
	char		*r_dup = strdup(s);
	char		*f_dup = ft_strdup(s);

	check_str("ft_strdup", r_dup, f_dup);
	free(r_dup);
	free(f_dup);
}

/* ------------------------------------------------------------------------- */
/*                                   MAIN                                    */
/* ------------------------------------------------------------------------- */

int	main(void)
{
	printf("===========================================\n");
	printf("   TESTER COMPLET LIBFT - FONCTIONS EN JAUNE\n");
	printf("===========================================\n");
	test_character_checks();
	test_casing_conversions();
	test_string_length_and_conv();
	test_string_search_and_cmp();
	test_memory_modifications();
	test_memory_search_and_cmp();
	test_allocation_functions();
	printf("\n===========================================\n");
	printf("RÉSULTATS : ");
	if (g_failure == 0)
		printf(GREEN "%d SUCCESS / 0 FAILURE 🎉\n" RESET, g_success);
	else
		printf(RED "%d SUCCESS / %d FAILURE(S) ❌\n" RESET, g_success, g_failure);
	printf("===========================================\n");
	return (g_failure == 0 ? 0 : 1);
}
