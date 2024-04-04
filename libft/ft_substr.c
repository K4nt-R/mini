/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:50:53 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/17 15:00:24 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (start > s_len)
		start = s_len;
	if (len >= s_len - start)
		len = s_len - start;
	c = ft_calloc(len + 1, sizeof(char));
	if (!c)
		return (NULL);
	if (start < s_len && len >= 1)
	{
		if (i < len && s[start + i] != '\0')
			ft_memcpy(c, s + start, len);
	}
	return (c);
}
