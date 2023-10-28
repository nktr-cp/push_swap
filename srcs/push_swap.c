/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:20:58 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/28 16:32:24 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_target_index(t_list *stack_a, t_list *stack_b)
{
	t_list	*tmp_a;
	int		diff;
	int		max_val;

	max_val = 0;
	while (stack_b)
	{
		tmp_a = stack_a;
		diff = INT_MAX;
		while (tmp_a)
		{
			if (tmp_a->val > max_val)
				max_val = tmp_a->val;
			if (diff > tmp_a->val - stack_b->val && tmp_a->val > stack_b->val)
				diff = update_target_index(tmp_a, stack_b);
			tmp_a = tmp_a->next;
		}
		if (stack_b->val > max_val)
			update_index(stack_a, stack_b, max_val);
		stack_b = stack_b->next;
	}
}

int	calc_steps(int cost_a, int cost_b)
{
	int	steps;

	steps = 0;
	while (cost_a || cost_b)
	{
		if (cost_a > 0 && cost_b > 0)
		{
			steps++;
			cost_a--;
			cost_b--;
		}
		else if (cost_a < 0 && cost_b < 0)
		{
			steps++;
			cost_a++;
			cost_b++;
		}
		else
		{
			steps += (ft_abs(cost_a) + ft_abs(cost_b));
			cost_a = 0;
			cost_b = 0;
		}
	}
	return (steps);
}

void	stack_move(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	t_list	*tmp;
	int		cost_a_optim;
	int		cost_b_optim;
	int		steps;

	tmp = *stack_b_ptr;
	steps = INT_MAX;
	while (tmp)
	{
		if (calc_steps(tmp->cost_a, tmp->cost_b) < steps)
		{
			cost_a_optim = tmp->cost_a;
			cost_b_optim = tmp->cost_b;
			steps = calc_steps(tmp->cost_a, tmp->cost_b);
		}
		tmp = tmp->next;
	}
	do_optimized_rotation(stack_a_ptr, stack_b_ptr, cost_a_optim, cost_b_optim);
}

void	sort_stack_end(t_list **stack_ptr)
{
	int		len;
	int		min_idx;
	t_list	*tmp;

	init_index(*stack_ptr, NULL);
	min_idx = 0;
	tmp = *stack_ptr;
	while (tmp)
	{
		if (tmp->val == 1)
		{
			min_idx = tmp->idx;
			break ;
		}
		tmp = tmp->next;
	}
	len = ft_lstsize(*stack_ptr);
	if (min_idx * 2 > len)
		min_idx = - (len - min_idx);
	do_optimized_rotation(stack_ptr, NULL, min_idx, 0);
}

void	push_swap(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	if (ft_lstsize(*stack_a_ptr) <= 6)
	{
		under_six(stack_a_ptr, stack_b_ptr);
		return ;
	}
	init_stacks(stack_a_ptr, stack_b_ptr);
	while (*stack_b_ptr || !check_sorted(stack_a_ptr))
	{
		init_index(*stack_a_ptr, *stack_b_ptr);
		get_target_index(*stack_a_ptr, *stack_b_ptr);
		initialize_cost(*stack_a_ptr, *stack_b_ptr);
		stack_move(stack_a_ptr, stack_b_ptr);
		pa(stack_a_ptr, stack_b_ptr);
		if (*stack_b_ptr == NULL)
			sort_stack_end(stack_a_ptr);
	}
}
