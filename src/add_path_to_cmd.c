/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_path_to_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:45:28 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/01 20:27:44 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_both(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*f;

	i = -1;
	f = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 2), sizeof(char));
	if (!f)
		return (free(s1), NULL);
	while (s1[++i])
		f[i] = s1[i];
	f[i] = '/';
	i++;
	j = -1;
	while (s2[++j] && s2[j] != ' ')
	{
		f[i] = s2[j];
		i++;
	}
	free(s1);
	return (f);
}

int	add_path_to_command(char **env, char **command, t_executable *executable)//t_main *main,
{
	int		i;
	int		r;

	i = -1;
    if (command[1] && ft_strchr(command[1], '/') != 0)
		return (1);
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			executable->command_to_exec = ft_split(env[i] + 5, ':');
			if (!executable->command_to_exec)
				return (-1);
			r = -1;
			// dprintf(2, "command exec: %s\n", command_to_exec[i]);
			while (executable->command_to_exec[++r])
			{
				executable->command_to_exec[r] = \
				ft_strjoin_both(executable->command_to_exec[r], command[0]);
				if (!executable->command_to_exec[r])
					return (-1);
			}
			return (0);
		}
	}
	return (-2);
}