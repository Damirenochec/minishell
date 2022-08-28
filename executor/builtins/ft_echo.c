#include "../../include/minishell.h"

static int	ft_nb_args(t_list *cmd_list)
{
	int	i;

	i = 0;
	while (cmd_list->value[i])
		i++;
	return (i);
}

void	ft_echo(t_list *cmd_list)
{
	size_t	i;
	size_t	newline;

	newline = 0;
	i = 0;
	if (ft_nb_args(cmd_list) > 1)
	{
		while (cmd_list->value[i] && ft_strncmp(cmd_list->value, "-n", 2) == 0)
		{
			newline = 1;
			i++;
		}
		while (cmd_list->value[i])
		{
			printf("%s", cmd_list->value[i]);
			i++;
		}
	}
	return;
}