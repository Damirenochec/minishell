#include "../../include/minishell.h"

int	ft_pwd(void)
{
	char path[PATH_MAX];

	if (getcwd(path, PATH_MAX))
	{
		printf("%s", path);
		return (SUCCESS);
	}
	else
		return (ERROR);
}