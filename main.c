/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprost <cprost@student.42belgium.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:51:00 by cprost            #+#    #+#             */
/*   Updated: 2026/05/05 11:38:48 by cprost           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void delcontent(void *content)
{
	free(content);
	content = NULL;
}

static void fakedel(void *content)
{
    (void)content;
}

static t_list *build_lst(t_list *head, int n)
{
	int i;
	char s[n];
	t_list *new;

	i = 0;
	while (i < n)
	{
		new = (t_list *)ft_calloc(1, sizeof(t_list));
		if (!new)
		{
			ft_lstclear(&head, delcontent);
			printf("ʕノ•ᴥ•ʔノ ︵ ┻━┻  ");
			return (NULL);
		}
		s[i] = 97 + i;
		new->content = ft_strdup(&s[i]);
		new->next = head;
		head = new;
		i++;
	}
	return (head);
}

// for ft_strmapi: char (*)(unsigned int, char)
static char	f1(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		c = ft_toupper(c);
	return (c);
}

// for ft_striteri: void (*)(unsigned int, char *)
static void	f2(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = ft_toupper(*c);
}

// for ft_lstiter / ft_lstmap del: void (*)(void *)
static void	f3(void *c)
{
	printf("from *f> %s\n", (char *)c);
}

// for ft_lstmap: void *(*)(void *)
static void	*f4(void *c)
{
	char	*s;
	int		i;

	s = ft_strdup((char *)c);
	i = -1;
	while (s[++i])
		s[i] = ft_toupper(s[i]);
	return (s);
}

int main(int argc, char **v)
{
	t_list *head = NULL;
	t_list *node = NULL;
	int fd;

	if (argc < 2) // [0] .out name [1] f name [2] 0=lib 1=ft [3]+ args
	{
		printf("incorrect entries");
		return (1);
	}

	if (strcmp(v[1], "ft_atoi") == 0)
	{
		int (*f)(const char *);
		f = v[2][0] == '1' ? ft_atoi : atoi;
		printf("ft_atoi: %d\n", f(v[3]));
	}

	else if (strcmp(v[1], "ft_bzero") == 0)
	{
		void (*f)(void *, size_t);
		f = v[2][0] == '1' ? ft_bzero : bzero;
		char *c = v[3];
		size_t i = atoi(v[4]);
		f(c, i);
		size_t j = 0;
		printf("ft_bzero:\n");
		while (j < i)
		{
			printf("[%zu]: %d\n", j, (unsigned char)c[j]);
			j++;
		}
	}

	else if (strcmp(v[1], "ft_calloc") == 0)
	{
		void *(*f)(size_t, size_t);
		size_t nmemb;
		size_t size;
		size_t j;

		f = v[2][0] == '1' ? ft_calloc : calloc;
		nmemb = (size_t)atoi(v[3]);
		size = (size_t)atoi(v[4]);
		void *ptr = f(nmemb, size);
		j = 0;
		while (j < nmemb * size)
		{
			printf("[%zu]: %d\n", j, ((unsigned char *)ptr)[j]);
			j++;
		}
		free(ptr);
	}

	else if (strcmp(v[1], "ft_isalnum") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_isalnum : isalnum;
		printf("ft_isalnum: %d\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_isalpha") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_isalpha : isalpha;
		printf("ft_isalpha: %d\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_isascii") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_isascii : isascii;
		printf("ft_isascii: %d\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_isdigit") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_isdigit : isdigit;
		printf("ft_isdigit: %d\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_isprint") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_isprint : isprint;
		printf("ft_isprint: %d\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_itoa") == 0)
	{
		printf("res: %s", ft_itoa(atoi(v[2])));
	}

	else if (strcmp(v[1], "ft_memchr") == 0)
	{
		void *(*f)(const void *, int, size_t);
		f = v[2][0] == '1' ? ft_memchr : memchr;
		printf("ft_memchr %s\n",
			   (char *)f((const void *)v[3], atoi(v[4]), (size_t)atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_memcmp") == 0)
	{
		int (*f)(const void *, const void *, size_t);
		f = v[2][0] == '1' ? ft_memcmp : memcmp;
		printf("ft_memcmp: %d\n", f((const void *)v[3], (const void *)v[4], (size_t)atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_memcpy") == 0)
	{
		void *(*f)(void *, const void *, size_t);
		f = v[2][0] == '1' ? ft_memcpy : memcpy;
		printf("ft_memcpy: %s\n", (unsigned char *)f(v[3], v[4], (size_t)atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_memmove") == 0)
	{
		void *(*f)(void *, const void *, size_t);
		f = v[2][0] == '1' ? ft_memmove : memmove;
		printf("ft_memmove: %s\n", (unsigned char *)f(v[3], v[4], (size_t)atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_memset") == 0)
	{
		void	*(*f)(void *, int, size_t);
		size_t	len;
		size_t	j;

		f = v[2][0] == '1' ? ft_memset : memset;
		len = ft_strlen(v[3]);
		f(v[3], atoi(v[4]), (size_t)atoi(v[5]));
		j = 0;
		printf("ft_memset:\n");
		while (j < len)
		{
			printf("[%zu]: %d\n", j, (unsigned char)v[3][j]);
			j++;
		}
	}

	else if (strcmp(v[1], "ft_putchar_fd") == 0)
	{
		fd = open(v[2], O_RDWR | O_CREAT, 0644);
		ft_putchar_fd(v[3][0], fd);
		close(fd); // then cat file
	}

	else if (strcmp(v[1], "ft_putstr_fd") == 0)
	{
		fd = open(v[2], O_RDWR | O_CREAT | O_APPEND, 0644);
		ft_putstr_fd(v[3], fd);
		close(fd); // then cat file
	}

	else if (strcmp(v[1], "ft_putendl_fd") == 0)
	{
		fd = open(v[2], O_RDWR | O_CREAT | O_APPEND, 0644);
		ft_putendl_fd(v[3], fd);
		close(fd); // then cat file with -e to see $
	}

	else if (strcmp(v[1], "ft_putnbr_fd") == 0)
	{
		fd = open(v[2], O_RDWR | O_CREAT | O_APPEND, 0644);
		ft_putnbr_fd(atoi(v[3]), fd);
		close(fd); // then cat file
	}

	else if (strcmp(v[1], "ft_split") == 0)
	{
		char **arr = ft_split(v[2], (char)v[3][0]);
		int i = 0;
		int words = atoi(v[4]);
		printf("ft_split:\n");
		while (i < words)
		{
			printf("%s\n", arr[i]);
			i++;
		}
	}

	else if (strcmp(v[1], "ft_strchr") == 0)
	{
		char *(*f)(const char *, int);
		f = v[2][0] == '1' ? ft_strchr : strchr;
		printf("ft_strchr:  %s\n", (unsigned char *)f(v[3], atoi(v[4])));
	}

	else if (strcmp(v[1], "ft_strdup") == 0)
	{
		char *(*f)(const char *);
		f = v[2][0] == '1' ? ft_strdup : strdup;
		char *dup = f(v[3]);
		printf("orig value: %s\n", v[3]);
		printf("orig address: %p\n", (void *)v[3]);
		printf("dup value: %s\n", dup);
		printf("dup address: %p\n", (void *)dup);
		free(dup);
	}

	else if (strcmp(v[1], "ft_striteri") == 0)
	{
		char *ch = v[2];
		ft_striteri(ch, f2);
		printf("%s", ch);
	}

	else if (strcmp(v[1], "ft_strjoin") == 0)
	{
		printf("ft_strjoin: %s\n", ft_strjoin(v[2], v[3]));
	}

	else if (strcmp(v[1], "ft_strlcat") == 0)
	{
		size_t (*ft)(char *, const char *, size_t);
		ft = v[2][0] == '1' ? ft_strlcat : strlcat;
		printf("ft_strlcat: %zu\n", ft(v[3], v[4], atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_strlcpy") == 0)
	{
		size_t (*f)(char *, const char *, size_t);
		f = v[2][0] == '1' ? ft_strlcpy : strlcpy;
		f(v[3], v[4], atoi(v[5]));
		printf("ft_strlcpy: %s\n", v[3]);
	}

	else if (strcmp(v[1], "ft_strlen") == 0)
	{
		printf("strlen:\n ft: %zu\n", ft_strlen(v[3]));
		printf("lib: %zu\n", strlen(v[3]));
	}

	else if (strcmp(v[1], "ft_strmapi") == 0)
	{
		printf("%s", ft_strmapi(v[2], f1));
	}

	else if (strcmp(v[1], "ft_strncmp") == 0)
	{
		const char *s1 = v[3];
		const char *s2 = v[4];
		printf("strncmp:\n ft: %d\n", ft_strncmp(s1, s2, (size_t)atoi(v[5])));
		printf("lib: %d\n", strncmp(s1, s2, (size_t)atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_strnstr") == 0)
	{
		char *(*f)(const char *, const char *, size_t);
		f = v[2][0] == '1' ? ft_strnstr : strnstr;
		printf("strnstr:  %s\n", (char *)f((const char *)v[3],
										   (const char *)v[4], (size_t)atoi(v[5])));
	}

	else if (strcmp(v[1], "ft_strrchr") == 0)
	{
		char *(*f)(const char *, int);
		f = v[2][0] == '1' ? ft_strrchr : strrchr;
		printf("ft:  %s\n", f((const char *)v[3], atoi(v[4])));
	}

	else if (strcmp(v[1], "ft_strtrim") == 0)
	{
		printf("result: %s", ft_strtrim(v[2], v[3]));
	}

	else if (strcmp(v[1], "ft_substr") == 0)
	{
		printf("%s", ft_substr(v[2], atoi(v[3]), (size_t)atoi(v[4])));
	}

	else if (strcmp(v[1], "ft_tolower") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_tolower : tolower;
		printf("ft_tolower %c\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_toupper") == 0)
	{
		int (*f)(int);
		f = v[2][0] == '1' ? ft_toupper : toupper;
		printf("ft_toupper %c\n", f(atoi(v[3])));
	}

	else if (strcmp(v[1], "ft_lstnew") == 0)
	{
		node = ft_lstnew(v[2]);
		printf("content: %s\n", (char *)node->content);
		printf("next: %p\n", node->next);
		free(node);
	}

	else if (strcmp(v[1], "ft_lstadd_front") == 0)
	{
		head = ft_lstnew(v[2]);
		node = ft_lstnew(v[3]);
		ft_lstadd_front(&head, node);
		printf("head: %s\n", (char *)head->content);
	}

	else if (strcmp(v[1], "ft_lstadd_back") == 0)
	{
		head = ft_lstnew(v[2]);
		node = ft_lstnew(v[3]);
		ft_lstadd_back(&head, node);
		printf("last: %s\n", (char *)head->next->content);
		ft_lstclear(&head, fakedel);
	}

	else if (strcmp(v[1], "ft_lstsize") == 0)
	{
		head = build_lst(NULL, atoi(v[2]));
		printf("size: %d\n", ft_lstsize(head));
	}

	else if (strcmp(v[1], "ft_lstlast") == 0)
	{
		head = build_lst(NULL, atoi(v[2]));
		printf("last: %s\n", (char *)ft_lstlast(head)->content);
	}

	else if (strcmp(v[1], "ft_lstdelone") == 0)
	{
		node = ft_lstnew(v[2]);
		ft_lstdelone(node, fakedel);
		printf("lstdelone: ok\n");
	}

	else if (strcmp(v[1], "ft_lstclear") == 0)
	{
		head = build_lst(NULL, atoi(v[2]));
		ft_lstclear(&head, fakedel);
		printf("lstclear: %s\n", head ? "KO" : "ok");
	}

	else if (strcmp(v[1], "ft_lstiter") == 0)
	{
		head = build_lst(NULL, atoi(v[2]));
		ft_lstiter(head, f3);
	}

	else if (strcmp(v[1], "ft_lstmap") == 0)
	{
		head = build_lst(NULL, atoi(v[2]));
		t_list *mapped = ft_lstmap(head, (void *)f4, delcontent);
		ft_lstiter(mapped, f3);
	}

	return (0);
}
