/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:26:57 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/28 16:47:18 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*cur;

	size = 0;
	cur = lst;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return (size);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cur;

	if (lst == NULL)
		return (NULL);
	cur = lst;
	while (cur->next)
		cur = cur->next;
	return (cur);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (lst == NULL)
		return ;
	cur = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (cur->next)
		cur = cur->next;
	cur->next = new;
}

void	ft_lstclear(t_list **lst)
{
	t_list	*cur;
	t_list	*next;

	if (lst == NULL)
		return ;
	cur = *lst;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*lst = NULL;
}
