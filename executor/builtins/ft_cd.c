#include "../../include/minishell.h"

static char	*get_env_path(t_list *env_list, char *str, size_t length)
{
	char	*olddir;
	int		k;
	int		j;
	int		str_alloc;

	while (env_list && env_list->next)
	{
		if (ft_strncmp(env_list->value, str, length) == 0)
		{
			str_alloc = ft_strlen(env_list->value);
			if (!(olddir = malloc(sizeof(char) * str_alloc + 1)))
				return (NULL);
			k = 0;
			j = 0;
			while (env_list->value[k++])
			{
				if (k > (int) length)
					olddir[j++] = env_list->value[i];
			}
			olddir[j] = '\0';
			return (olddir);
		}
		env_list = env_list->next;
	}
	return (NULL);
}

static int	go_to_path(int opt, t_list *env_list)
{
	int		ret;
	char	*path;

	path = NULL;
	if (opt == 0)
	{
		update_old_folder(env_list);
		path = get_env_path(env_list, "HOME", 4);
				if (!path)
				{
					printf("Shell. CD Home is not set");
					return (ERROR);
				}
	}
	else if (opt == 1)
	{
		path = get_env_path(env_list, "OLDPWD", 6);
		if (!path)
		{
			printf("Shell. CD OLDPWD is not set");
			return (ERROR);
		}
	}
	ret = chdir(path);
	ft_memdel(path);
	return (ret);
}

static int	update_old_folder(t_list *env_list)
{
	char	cwd[PATH_MAX];
	char	*old_dir;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (ERROR);
	if (!(old_dir = ft_strdup(cwd)))
		return (ERROR);
	if (ft_is_in_env(env_list, "OLDPWD=", old_dir) == 0)
		ft_add_env(old_dir, env_list);
	ft_memdel(old_dir);
	return (SUCCESS);
}

int	ft_cd(t_list *cmd_list, t_list *env_list)
{
	int	ret;

	if (!cmd_list[0])
		return (go_to_path(0, env_list)); //вернуться в папк
	if (ft_strncmp(cmd_list[1]), "-", 1) == 0
		ret = go_to_path(1, env_list);
	else
	{
		update_old_folder(env_list);
		ret = chdir(args[1]);
		if (ret < 0)
			ret = ret * -1;
		if (ret != 0)
			write_error(cmd_list->key);
	}
	return (ret);
}
