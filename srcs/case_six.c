/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_six.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:45:10 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/28 16:23:20 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *stack_a)
{
	t_list	*tmp;
	int		minval;

	minval = stack_a->val;
	tmp = stack_a;
	while (tmp)
	{
		minval = ft_min(minval, tmp->val);
		tmp = tmp->next;
	}	
	return (minval);
}

bool	is_in_lowerhalf(t_list *stack_a)
{
	t_list	*tmp;
	int		minval;
	int		minidx;

	tmp = stack_a;
	minval = get_min(stack_a);
	minidx = 0;
	while (tmp)
	{
		if (tmp->val == minval)
			break ;
		tmp = tmp->next;
		minidx++;
	}
	if (minidx > ft_lstsize(stack_a) / 2)
		return (false);
	return (true);
}

void	push_min(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	int	minval;

	minval = get_min(*stack_a_ptr);
	while ((*stack_a_ptr)->val != minval)
	{
		if (is_in_lowerhalf(*stack_a_ptr))
			ra(stack_a_ptr);
		else
			rra(stack_a_ptr);
	}
	pb(stack_a_ptr, stack_b_ptr);
}

void	under_six(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	int	cnt;

	cnt = 0;
	while (ft_lstsize(*stack_a_ptr) > 3)
	{
		push_min(stack_a_ptr, stack_b_ptr);
		cnt++;
	}
	under_three(stack_a_ptr);
	while (cnt--)
		pa(stack_a_ptr, stack_b_ptr);
}
