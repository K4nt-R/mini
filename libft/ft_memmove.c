/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:31:31 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/08 18:51:15 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if ((dest - src) > 0)
	{
		while (n != 0)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
		ft_memcpy(dest, src, n);
	return ((char *)dest);
}
