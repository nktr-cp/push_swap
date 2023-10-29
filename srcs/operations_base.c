/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:12:40 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 18:50:51 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	next = head->next;
	tmp = head->val;
	head->val = next->val;
	next->val = tmp;
	return (0);
}

int	ft_stack_push(t_list **stack_to, t_list **stack_from)
{
	t_list	*head_to;
	t_list	*new_head;

	if (ft_lstsize(*stack_from) == 0)
		return (1);
	head_to = *stack_to;
	new_head = *stack_from;
	*stack_from = (*stack_from)->next;
	if (head_to == NULL)
	{
		head_to = new_head;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		new_head->next = head_to;
		*stack_to = new_head;
	}
	return (0);
}

int	ft_stack_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_lstlast(*stack);
	*stack = head->next;
	tail->next = head;
	head->next = NULL;
	return (0);
}

int	ft_stack_reverse_rotate(t_list **stack)
{
	t_list	*before_tail;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (1);
	before_tail = *stack;
	tail = ft_lstlast(*stack);
	while (before_tail)
	{
		if (before_tail->next->next == NULL)
			break ;
		before_tail = before_tail->next;
	}
	before_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
	return (0);
}
