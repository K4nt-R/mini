/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_acces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 20:13:57 by pdreneau          #+#    #+#             */
/*   Updated: 2024/04/01 20:28:29 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_acces(t_executable *executable)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	// if (utils->check == -2)//check si deja chemoin
	// 	return (-2);
	while (executable->command_to_exec[a])
	{
		if (access(executable->command_to_exec[a], F_OK) == 0)
		{
			b = 1;
			if (access(executable->command_to_exec[a], X_OK) == 0)
				return (a);
		}
		a++;
	}
	if (b == 1)
		return (-2);
	return (-1);
}