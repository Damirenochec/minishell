#include "../../include/minishell.h"

int	ft_pwd(void)
{
	char path[PATH_MAX];

	if (getcwd(path, PATH_MAX))
	{
		printf("%s", path);
		return (0);
	}
	else
		return (1);
}