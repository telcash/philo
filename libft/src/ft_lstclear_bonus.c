/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csalazar <csalazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:47:24 by csalazar          #+#    #+#             */
/*   Updated: 2024/09/19 12:00:06 by csalazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*n;
	t_list	*temp;

	if (*lst == NULL || del == NULL)
		return ;
	n = *lst;
	while (n)
	{
		temp = n->next;
		ft_lstdelone(n, del);
		n = temp;
	}
	*lst = NULL;
}
