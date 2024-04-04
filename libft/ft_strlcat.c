/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:27:26 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/17 12:57:35 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	f;

	f = 0;
	i = 0;
	j = 0;
	while (src[i] != 0)
		i++;
	while (dst[j] != '\0' && j < size)
		j++;
	while (src[f] && j + f + 1 < size)
	{
		dst[j + f] = src[f];
		f++;
	}
	if (j < size)
		dst[j + f] = '\0';
	return (i + j);
}
