/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:43:14 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 14:06:40 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_three(int *n, t_list **stack_a_ptr)
{
	n[0] = (*stack_a_ptr)->val;
	n[1] = (*stack_a_ptr)->next->val;
	n[2] = (*stack_a_ptr)->next->next->val;
}

void	sort_three(t_list **stack_a_ptr)
{
	int	n[3];

	init_three(n, stack_a_ptr);
	if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])
	{
		sa(stack_a_ptr, true);
		ra(stack_a_ptr, true);
	}
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		sa(stack_a_ptr, true);
	if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		rra(stack_a_ptr, true);
	if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		ra(stack_a_ptr, true);
	if (n[0] > n[1] && n[1] > n[2])
	{
		sa(stack_a_ptr, true);
		rra(stack_a_ptr, true);
	}
}

void	under_three(t_list **stack_a_ptr)
{
	int	siz;

	siz = ft_lstsize(*stack_a_ptr);
	if (siz <= 1 || check_sorted(stack_a_ptr))
		return ;
	if (siz == 2)
		ra(stack_a_ptr, true);
	else
		sort_three(stack_a_ptr);
}
