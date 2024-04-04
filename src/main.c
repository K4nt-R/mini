/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 17:17:06 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/02 10:59:00 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #define METACAR "|;&()<>"
#include "minishell.h"
#include <stdio.h>//a sup
#include <readline/readline.h>
#include <readline/history.h>

int malloc_token(char **linecut, t_token *token, int lenght)
{
	int	i;
	int	j;
	
	i = 0;
	// while (linecut[i])
	// 	i++;
	//token = malloc(2);
	// i = 0;
	while (linecut[i])
	{
		lenght = ft_strlen(linecut[i]);
		j = 0;
		while (linecut[i][j])
		{
			token->content = malloc (lenght * sizeof(char));
			token->content[lenght] = '\0';
			token->content[j] = linecut[i][j];
			j++;
		}
		i++;
	//	token->next = ????
	}
	return (0);
}

int	name_all_cmd(char **linecut, t_token *token)
{
	int	i;
	int	lenght;

	i = 0;
	lenght = ft_strlen(linecut[i]);
	if (lenght == 0)
		return (-1);
	malloc_token(linecut, token, lenght);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
//	t_token	token;
	char *line;
//	int		i;

//	i = 0;
	(void) argc;
	(void) env;
	(void) argv;
	while (1)
	{
		line = readline("minishell: ");
		printf("line = %s\n", line);
		parse(line);
		printf("new = %s \n", line);
		break;
//		token.content = "cat";
//		token.file = "Makefile test";// ouvre tt et travail sur le dernier sur les outfile
//		token.infile = 0;
//		if (receiving_and_executing_command(&token, env) == -1)
//			return (-1);
		// linecut = ft_split(line, ' ');
		// name_all_cmd(linecut, &token);
		// while (line[i])
		// {
		// 	check = ft_strrchr(OPERATOR, line[i]);
		// 	if (check != 0)
		// 		printf ("line[%d]: %c\n", i, line[i]);
		// 	i++;
		// }
//		while (wait(NULL) > 0)
//			;
	}
	
	//free(line);
	return (0);
}
