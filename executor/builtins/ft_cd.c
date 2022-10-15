#include "../../include/minishell.h"



static int	update_old_folder(t_list *env)
{
	char	cwd[PATH_MAX];
	char	*old_dir;

	if (getcwd(cwd, PATH_MAX) == NULL)
		return (ERROR);
	if (!(old_dir = ft_strjoin("OLDPWD=", cwd)))
		return (ERROR);
	if (is_in_env)
	//
	//
	//

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
			write_error(cmd_list);
	}
	return (ret);
}
