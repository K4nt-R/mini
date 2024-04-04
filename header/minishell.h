/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:07:09 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/02 10:47:37 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define OPERATOR "|;&()<>"
# define METACAR " \t\n"
# define OUT = 0;
# define OPEN = 0;


# include "libft.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef enum e_token_type
{
	PIPE = 0,
	CROCO_RIGHT = 1,
	CROCO_LEFT = 2,
	DOUBLE_CROCO_RIGHT = 3,
	DOUBLE_CROCO_LEFT = 4,
	SIMPLE_QUOTE = 5,
	DOUBLE_QUOTE = 6,
	WORD = 7,
	WORL_AND_ARGU = 8,
}	t_token_type;

// typedef enum s_open
// {
// 	OPEN
// }	t_open;

// typedef enum s_outfile
// {
// 	OUT
// }	t_outfile;

typedef	struct s_token
{
	char			*content;
	char			*file;
	char			*infile_name;
	char			*outfile_name;
	// t_token_type	type;
	int				infile;
	int				outfile;
	// t_token			*next;
}	t_token;

typedef struct s_executable
{
	char	**command_to_exec;
	int		check_command;
	int		check_path;
}	t_executable;

//receiving_command.c
int	receiving_and_executing_command(t_token *token, char **env);

//exec_command.c
int exec_command(t_token *token, int *fd_pipe, int last_pipe, char **env);

//child.c
int child(t_token *token, int *fd_pipe, int last_pipe, char **command, char **env);

//add_path_to_cmd.c
int	add_path_to_command(char **env, char **command, t_executable *executable);

//find_acces.c
int	find_acces(t_executable *executable);

//ft_close.c
int	ft_close(int fd);

//pasring
void	parse (char *line);

void ft_addspace(char **line, int i);
void ft_addspace_rev(char **line, int i);
#endif