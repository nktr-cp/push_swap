/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:27:46 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/28 16:39:59 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack_a(t_list **stack_a_ptr, int *cost)
{
	if (*cost < 0)
	{
		rra(stack_a_ptr);
		(*cost)++;
	}
	else if (*cost > 0)
	{
		ra(stack_a_ptr);
		(*cost)--;
	}
}

static void	rrr_and_adjust_cost(t_list **stack_a_ptr, t_list **stack_b_ptr,
					int *cost_a, int *cost_b)
{
	rrr(stack_a_ptr, stack_b_ptr);
	(*cost_a)++;
	(*cost_b)++;
}

static void	rr_and_adjust_cost(t_list **stack_a_ptr, t_list **stack_b_ptr,
					int *cost_a, int *cost_b)
{
	rr(stack_a_ptr, stack_b_ptr);
	(*cost_a)--;
	(*cost_b)--;
}

void	do_optimized_rotation(t_list **stack_a_ptr, t_list **stack_b_ptr,
					int cost_a, int cost_b)
{
	while (cost_a || cost_b)
	{
		if (cost_a < 0 && cost_b < 0)
			rrr_and_adjust_cost(stack_a_ptr, stack_b_ptr, &cost_a, &cost_b);
		else if (cost_a > 0 && cost_b > 0)
			rr_and_adjust_cost(stack_a_ptr, stack_b_ptr, &cost_a, &cost_b);
		else if (cost_a)
			rotate_stack_a(stack_a_ptr, &cost_a);
		else if (cost_b < 0)
		{
			rrb(stack_b_ptr);
			cost_b++;
		}
		else if (cost_b > 0)
		{
			rb(stack_b_ptr);
			cost_b--;
		}
	}
}
