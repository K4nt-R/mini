/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   receiving_command.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:23:03 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/01 15:29:49 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	receiving_and_executing_command(t_token *token, char **env)
{
	int	fd_pipe[2];
	int	last_pipe;
	
	//open last pipe
	int i = 0;
	while(i == 0)//token->next != NULL)
	{
		if(pipe(fd_pipe) == -1)
			return (-1);
		last_pipe = exec_command(token, fd_pipe, last_pipe, env);
		if (last_pipe == -1)
			return (-1);
		i++;
	}
	return (0);
}