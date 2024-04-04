/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 07:11:48 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/16 14:52:50 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*f;
	size_t	d;

	d = ft_strlen(s1);
	f = ft_calloc(((ft_strlen(s1) + ft_strlen(s2)) + 1), sizeof(char));
	if (!f)
		return (NULL);
	ft_memcpy(f, s1, d);
	ft_memcpy(f + d, s2, ft_strlen(s2));
	return (f);
}
