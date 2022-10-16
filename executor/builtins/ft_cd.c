#include "../../include/minishell.h"

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
		return (); //вернуться в папк
	if (ft_strncmp(cmd_list[1]), "-", 1) == 0
		ret = go_to_path(1, env);
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
