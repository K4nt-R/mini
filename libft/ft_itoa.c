/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <pdreneau@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:01:36 by pdreneau          #+#    #+#             */
/*   Updated: 2023/12/19 15:01:36 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	counting(long int n2, size_t count)
{
	while (n2 >= 10)
	{
		n2 = n2 / 10;
		count++;
	}
	count++;
	return (count);
}

static char	*writing(long int n2, size_t i, char *chaine, size_t count)
{
	if (chaine == NULL)
		return (NULL);
	while (i < count)
	{
		if (n2 >= 10)
		{
			count--;
			chaine[count] = n2 % 10 + '0';
			n2 = n2 / 10;
		}
		else
		{
			count--;
			chaine[count] = n2 % 10 + '0';
			n2 = n2 / 10;
		}
	}
	return (chaine);
}

char	*ft_itoa(int n)
{
	long int	n2;
	char		*chaine;
	size_t		i;
	size_t		count;

	count = 0;
	i = 0;
	n2 = (long int)n;
	if (n < 0)
	{
		n2 = -n2;
		i++;
		count++;
	}
	count = counting(n2, count);
	chaine = ft_calloc(count + 1, sizeof(char));
	if (!chaine)
		return (NULL);
	if (i == 1)
		chaine[0] = '-';
	writing(n2, i, chaine, count);
	return (chaine);
}
