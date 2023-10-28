/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:31:00 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/28 16:32:46 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	int		i;
	int		stack_size;

	stack_size = ft_lstsize(*stack_a_ptr);
	i = 0;
	while (i < stack_size)
	{
		if ((*stack_a_ptr)->val > stack_size / 2)
			pb(stack_a_ptr, stack_b_ptr);
		else
			ra(stack_a_ptr);
		i++;
	}
	while (ft_lstsize(*stack_a_ptr) > 3)
		pb(stack_a_ptr, stack_b_ptr);
	under_three(stack_a_ptr);
}

void	init_index(t_list *stack_a, t_list *stack_b)
{
	int		len;
	int		i;

	len = ft_lstsize(stack_a);
	i = 0;
	while (i < len)
	{
		stack_a->idx = i;
		stack_a = stack_a->next;
		i++;
	}
	len = ft_lstsize(stack_b);
	i = 0;
	while (i < len)
	{
		stack_b->idx = i;
		stack_b = stack_b->next;
		i++;
	}
}

int	update_target_index(t_list *stack_a, t_list *stack_b)
{
	int	diff;

	diff = stack_a->val - stack_b->val;
	stack_b->target_idx = stack_a->idx;
	return (diff);
}

void	initialize_cost(t_list *stack_a, t_list *stack_b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(stack_a);
	len_b = ft_lstsize(stack_b);
	while (stack_b)
	{
		if (stack_b->idx * 2 > len_b)
			stack_b->cost_b = - (len_b - stack_b->idx);
		else
			stack_b->cost_b = stack_b->idx;
		if (stack_b->target_idx > len_a / 2)
			stack_b->cost_a = - (len_a - stack_b->target_idx);
		else
			stack_b->cost_a = stack_b->target_idx;
		stack_b = stack_b->next;
	}
}

void	update_index(t_list *stack_a, t_list *stack_b, int value)
{
	int	min_val;

	min_val = value;
	while (stack_a)
	{
		if (stack_a->val < min_val)
		{
			min_val = stack_a->val;
			stack_b->target_idx = stack_a->idx;
		}
		stack_a = stack_a->next;
	}
}
