*This project has been created as part of the 42 curriculum by evanchoq*

# Libft - Votre toute première bibliothèque en C

## Description

Le projet **Libft** est le tout premier projet du cursus de l'école 42. L'objectif est de recréer une bibliothèque de fonctions usuelles de la bibliothèque C standard (`libc`), ainsi que d'autres fonctions utilitaires et de manipulation de listes chaînées.

Cette bibliothèque sert de fondation solide pour la suite du cursus C à 42, permettant d'assimiler l'allocation mémoire (`malloc`, `free`), la gestion des pointeurs et la manipulation des structures de données fondamentales.

---

## Fonctions incluses

### Partie 1 - Fonctions de la Libc
Réécriture des fonctions standards de la libc (sans utiliser de fonctions externes autorisées hormis `malloc` pour certaines) :

* **Gestion des caractères :** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`
* **Gestion des chaînes :** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`
* **Gestion de la mémoire :** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
* **Conversion :** `ft_atoi`

### Partie 2 - Fonctions supplémentaires
Fonctions additionnelles non présentes dans la libc ou sous une forme différente :

* `ft_substr` : Extrait une sous-chaîne à partir d'une chaîne.
* `ft_strjoin` : Concatène deux chaînes dans une nouvelle zone mémoire.
* `ft_strtrim` : Supprime les caractères d'un ensemble spécifié au début et à la fin d'une chaîne.
* `ft_split` : Découpe une chaîne en un tableau de chaînes selon un caractère séparateur.
* `ft_itoa` : Convertit un entier `int` en chaîne de caractères.
* `ft_strmapi` : Applique une fonction à chaque caractère d'une chaîne pour en créer une nouvelle.
* `ft_striteri` : Applique une fonction à chaque caractère d'une chaîne en le modifiant sur place.
* `ft_putchar_fd` / `ft_putstr_fd` / `ft_putendl_fd` / `ft_putnbr_fd` : Écrivent respectivement un caractère, une chaîne, une chaîne avec saut de ligne ou un nombre sur un descripteur de fichier (`fd`).

### Partie Bonus - Gestion des listes chaînées
Utilisation de la structure `t_list` :

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;
```

* `ft_lstnew` : Crée un nouveau nœud.
* `ft_lstadd_front` : Ajoute un nœud au début de la liste.
* `ft_lstsize` : Compte le nombre de nœuds dans la liste.
* `ft_lstlast` : Renvoie le dernier nœud de la liste.
* `ft_lstadd_back` : Ajoute un nœud à la fin de la liste.
* `ft_lstdelone` : Libère la mémoire d'un nœud spécifique.
* `ft_lstclear` : Supprime et libère un nœud et tous ses successeurs.
* `ft_lstiter` : Applique une fonction au contenu de chaque nœud.
* `ft_lstmap` : Crée une nouvelle liste résultant de l'application d'une fonction sur chaque nœud.

---

## Instructions d'installation et de compilation

### Prérequis
* Un compilateur C (`gcc` ou `clang`)
* La commande `make`

### Compilation
Pour compiler la bibliothèque obligatoire :
```bash
make
```
Ceci générera l'archive statique `libft.a` à la racine du dépôt.

### Autres règles du Makefile
* `make clean` : Supprime tous les fichiers objets (`.o`).
* `make fclean` : Supprime les fichiers objets et l'archive `libft.a`.
* `make re` : Recompile entièrement le projet (`fclean` puis `all`).

### Utilisation dans un projet
Pour utiliser cette bibliothèque dans vos propres programmes C :

1. Incluez le header dans votre code C :
   ```c
   #include "libft.h"
   ```
2. Compilez votre programme en liant `libft.a` :
   ```bash
   cc -Wall -Wextra -Werror main.c -L. -lft -o mon_programme
   ```

---

## Ressources et Utilisation de l'IA

### Ressources de référence
* Man pages de Linux (`man 3 strlen`, `man 3 malloc`, etc.)
* Standard C Library documentation : man [fonction]

### Usage de l'IA dans ce projet
Conformément aux directives pédagogiques de l'école 42 :
* **Usage de l'IA :** Utiliser pour comprendre les sujet et traduire le sujet, mon niveau en anglais est moyen et aussi des aide pour certaine fonction