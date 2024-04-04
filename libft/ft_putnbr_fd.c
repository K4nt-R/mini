/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 07:22:54 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/17 11:49:43 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

void	ft_putnbr_fd(int n, int fd)
{
	size_t	n2;

	if (n == -2147483648)
		write (fd, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			n2 = (size_t) - n;
			write (fd, "-", 1);
		}
		else
			n2 = (size_t)n;
		if (n2 < 10)
		{
			n2 = n2 + 48;
			write (fd, &n2, 1);
		}
		else
		{
			ft_putnbr_fd((n2 / 10), fd);
			n2 = n2 % 10 + 48;
			write (fd, &n2, 1);
		}
	}
}
