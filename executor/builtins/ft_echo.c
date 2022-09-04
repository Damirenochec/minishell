#include "../../include/minishell.h"

static int	ft_nb_args(t_list *cmd_list)
{
	int	i;

	i = 0;
	while (cmd_list->value[i])
		i++;
	return (i);
}

int	ft_echo(t_list *cmd_list)
{
	size_t	i;
	size_t	newline;

	newline = 0;
	i = 1;
	if (ft_nb_args(cmd_list) > 1)
	{
		while (cmd_list->value[i] && ft_strncmp(cmd_list->value[i], "-n", 2) == 0)
		{
			newline = 1;
			i++;
		}
		while (cmd_list->value[i])
		{
			printf("%s", cmd_list->value[i]);
			if (cmd_list->value[i + 1] && cmd_list->value[i][0] != '\0')
					printf(' ');
			i++;
		}
	}
	if (newline == 0)
		printf('\n');
	return (0);
}