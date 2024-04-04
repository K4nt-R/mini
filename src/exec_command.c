/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:33:49 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/01 19:30:04 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int exec_command(t_token *token, int *fd_pipe, int last_pipe, char **env)
{
    char    **command;
    int     pid;
    
    command = ft_split(token->content, ' ');//malloc
    if (!command)
        return (-1);
    if (token->infile == 0)// open == 0
    {
        last_pipe = open(token->file, O_WRONLY, 0666);
        if (last_pipe == -1)
            return (-1);
    }
    pid = fork();
    if (pid == -1)
        return (-1);
    if (pid == 0)
        child(token, fd_pipe, last_pipe, command, env);//cest une focntion
    return (0);
    //exit(1);//securiter
}