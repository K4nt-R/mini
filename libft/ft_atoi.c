/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:29:33 by pdreneau          #+#    #+#             */
/*   Updated: 2024/02/15 16:46:05 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	cheking(int b)
{
	if (b < 0)
		return (0);
	else
		return (-1);
}

long int	ft_atol(const char *nptr)
{
	long int	i;
	int			b;

	b = 1;
	i = 0;
	while (*nptr == '\f' || *nptr == '\n' || \
			*nptr == '\r' || *nptr == '\t' || *nptr == '\v' || *nptr == ' ')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			b = -1;
		nptr++;
	}
	while (47 < *nptr && *nptr < 58)
	{
		if (((i * 10 + *nptr - 48) / 10) != i)
			return ((long int)cheking(b));
		i = i * 10 + *nptr - 48;
		nptr++;
	}
	if (b == -1)
		i = -i;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	if (*nptr)
	{
		return (ft_atol(nptr));
	}
	return (0);
}
