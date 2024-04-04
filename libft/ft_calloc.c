/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:00:50 by pdreneau          #+#    #+#             */
/*   Updated: 2023/12/19 15:00:53 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*e;

	if (nmemb == 0 || size == 0)
	{
		e = malloc(0);
		if (!e)
			return (NULL);
		return (e);
	}
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	e = malloc(size * nmemb);
	if (!e)
		return (NULL);
	ft_bzero(e, nmemb * size);
	return (e);
}
