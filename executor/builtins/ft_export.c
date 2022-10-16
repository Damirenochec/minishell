#include "../../include/minishell.h"

//char	ft_get_env_name(void *dest, void *src)
//{
//	int		i;
//	char	tmp[BUFFER_SIZE];
//
//	tmp = (char*)src;
//	i = 0;
//	while (tmp[i] && ft_strlen(src) < BUFFER_SIZE)
//}

// функция добавляет переменную окружения.

int	ft_add_env(char	*env_value, t_list *env_list)
{
	t_list	*new;
	t_list	*tmp;

	if (env_list && env_list->next == NULL)
	{
		env_list->value = ft_strdup(env_value);
		return (SUCCESS);
	}
	if (!(new = malloc(sizeof(t_list))))
		return (-1);
	new->value = ft_strdup(env_value);
	while (env_list && env_list->next && env_list->next->next)
		env_list = env_list->next;
	tmp = env_list->next;
	env_list->next = new;
	new->next = tmp;
	return (SUCCESS);
}

// функция ниже проверяет есть ли переменная в ENV и какое там значение
int	ft_is_in_env(t_list *env_list, char *env_key, char *env_value)
{
	while (env_list && env_list->next)
	{
		if (ft_strncmp(env_key, env_list->key, ft_strlen(args)) == 0)
		{
			ft_memdel(env_list->value)
			env_list->value = ft_strdup(env_value);
			return (1);
		}
		env_list = env_list->next;
	}
	return (SUCCESS);
}