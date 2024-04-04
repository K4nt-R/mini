/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:18:04 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/16 14:28:58 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	first(char const *s1, char const *set)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (set[i])
	{
		if (s1[count] == set[i])
		{
			count++;
			i = 0;
		}
		else
			i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	count;
	size_t	count2;
	size_t	i;
	char	*e;

	count2 = ft_strlen(s1);
	i = 0;
	count = first(s1, set);
	while (set[i] && count2 - 1 >= count)
	{
		if (s1[count2 - 1] == set[i])
		{
			count2--;
			i = 0;
		}
		else
			i++;
	}
	e = ft_calloc(count2 - count + 1, sizeof(char));
	if (!e)
		return (NULL);
	ft_memcpy(e, s1 + count, (count2 - count));
	return (e);
}
