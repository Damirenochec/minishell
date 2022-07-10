//#include "../include/minishell.h"
#include "../include/executor.h"
#include <stdio.h>
#include <stdlib.h>

static int	ft_strncmp1(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n > 0 && (*str1 || *str2))
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);

static char	*ft_strdp(const char *s1)
{
	char	*ptr;
	char	*ptr1;

	ptr = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!ptr)
		return (NULL);
	ptr1 = ptr;
	while (*s1)
	{
		*ptr++ = *s1++;
	}
	*ptr = '\0';
	return (ptr1);
}

void	ft_echo (t_list *args)
{
	t_list	*tmp;

	tmp = (struct s_list*)malloc(sizeof(struct s_list));
	tmp = args;
	if (tmp && !ft_strncmp1("-n", tmp->next->word, 2))
	{
		while (tmp && !ft_strncmp1("|", tmp->word, 1))
//		*(tmp->word) != '|')
		{
			printf("%s", tmp->word);
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp && !ft_strncmp1("|", tmp->word, 1))
//		*(tmp->word) != '|')
		{
			printf("%s", tmp->word);
			tmp = tmp->next;
		}
		printf("\n");
	}
	return;
}

int	main (int argc, char **argv)
{
	t_list	*args;
	t_list	*tmp;
	int	i;

	i = 1;
	args = (struct s_list*)malloc(sizeof(struct s_list));
	tmp = (struct s_list*)malloc(sizeof(struct s_list));
	if (!args || !tmp)
		return (1);
	if (argc < 2)
		return (1);
	tmp = args;
	while (argv[i])
	{
		tmp->word = ft_strdp(argv[i]);
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	ft_echo(args);
	return (0);
}
