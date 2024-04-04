/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:48:53 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/16 18:23:00 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s[i] == ((char)c))
		return (((char *)s) + i);
	while (i > 0)
	{
		i--;
		if (s[i] == ((char)c))
			return (((char *) s) + i);
	}
	return (0);
}
