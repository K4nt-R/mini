/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:32:10 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/17 11:51:53 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **f, size_t z)
{
	size_t	i;

	i = 0;
	while (i < z)
	{
		free(f[i]);
		i++;
	}
	free(f);
	return (NULL);
}

static size_t	countingword(const char *dest, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (dest[i])
	{
		if (dest[i] != c && (dest[i + 1] == c || dest[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char	**chaining(char c, char *s, char **f, size_t z)
{
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	while (s[start])
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		if (s[end] != c && s[end] != '\0')
		{
			while (s[end] != c && s[end] != '\0')
				end++;
			f[z] = ft_calloc(end - start + 1, sizeof(char ));
			if (!f[z])
				return (ft_free(f, z));
			ft_memcpy(f[z], s + start, end - start);
			z++;
			start = end;
		}
	}
	f[z] = NULL;
	return (f);
}

char	**ft_split(char const *s, char c)
{
	char	**f;
	size_t	testcount;
	size_t	z;

	z = 0;
	testcount = countingword(s, c);
	f = ft_calloc(testcount + 1, sizeof(char *));
	if (!f)
		return (NULL);
	f = chaining(c, (char *)s, f, z);
	return (f);
}
