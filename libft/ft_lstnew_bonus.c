/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdreneau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:12:53 by pdreneau          #+#    #+#             */
/*   Updated: 2023/11/28 08:06:29 by pdreneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*m;

	m = (t_list *) malloc(sizeof(t_list));
	if (!m)
		return (NULL);
	m->content = content;
	m->next = NULL;
	return (m);
}
