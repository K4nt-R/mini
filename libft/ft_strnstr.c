/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:16:26 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/09 15:37:43 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		x = 0;
		while (big[i + x] == little[x] && (i + x) <= len && little[x])
		{
			x++;
			if (x == ft_strlen(little) && i + x <= len)
				return (((char *)big) + i);
		}
		i++;
	}
	return (0);
}
