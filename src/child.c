/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 13:32:32 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/01 21:08:11 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int dup_in_child(int *fd_pipe, int last_pipe)
{
	fd_pipe[0] = ft_close(fd_pipe[0]);
	if (fd_pipe[0] == -1)
		return (-1);
	if (dup2(last_pipe, 0) == -1)
		return (-1);
	last_pipe = ft_close(last_pipe);
	if (last_pipe == -1)
		return (-1);
	// if (dup2(fd_pipe[1], 1) == -1)
	// 	return (-1);
	fd_pipe[1] = ft_close(fd_pipe[1]);
	if (fd_pipe[1] == -1)
		return (-1);
	return (0);
}

int child(t_token *token, int *fd_pipe, int last_pipe, char **command, char **env)
{
	t_executable executable;

	(void)token;
	if (dup_in_child(fd_pipe, last_pipe) == -1)
		return (-1);
	executable.check_command = add_path_to_command(env, command, &executable);
	if (executable.check_command == -1)
		return (-1);
	executable.check_path = find_acces(&executable);
	if (executable.check_path == -1 || executable.check_path == -2)
		return (-1);
	int	i = 0;
	while (command[i])
	{
		//dprintf(2, "just pr voir: %c\n", token->content[i]);
		dprintf(2, "%s\n", command[i]);
		i++;
	}
	dprintf(2, "command[1]: %d\n",last_pipe);
	dprintf(2, "command exec[%d]: %s\n",executable.check_path, executable.command_to_exec[executable.check_path]);
	dprintf(2, "command[0]: %s\n",command[0]);
	execve(executable.command_to_exec[executable.check_path], command, env);// ca marche pas
	exit(1);
}