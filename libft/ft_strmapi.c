/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:03:48 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/16 14:58:03 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*c;

	i = 0;
	c = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (c);
}
