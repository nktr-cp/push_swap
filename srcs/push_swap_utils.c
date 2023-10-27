/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:28:59 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 21:52:27 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// for debug
void	print_stack(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!tmp)
		ft_printf("given stack is empty.\n");
	while (tmp)
	{
		ft_printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
}

bool	check_sorted(t_list **stack)
{
	long long	prev;
	t_list		*lst;

	lst = *stack;
	prev = LLONG_MIN;
	while (lst)
	{
		if (prev > lst->val)
			return (false);
		prev = lst->val;
		lst = lst->next;
	}
	return (true);
}

t_list	*init_lst(int *numbers, int len)
{
	int		i;
	t_list	*new;
	t_list	*lst;

	i = 0;
	lst = NULL;
	while (i < len)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new->val = numbers[i];
		new->next = NULL;
		ft_lstadd_back(&lst, new);
		i++;
	}
	return (lst);
}

int	ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}