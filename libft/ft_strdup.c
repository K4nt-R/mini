/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 10:01:02 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/17 12:31:08 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	j;
	char	*e;

	j = 0;
	e = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!e)
		return (NULL);
	while (j < ft_strlen(s))
	{
		e[j] = s[j];
		j++;
	}
	e[j] = '\0';
	return ((char *)e);
}
