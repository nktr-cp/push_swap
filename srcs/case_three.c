/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:43:14 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 16:44:18 by knishiok         ###   ########.fr       */
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
	// 0 2 1
	if (n[0] < n[1] && n[1] > n[2] && n[0] < n[2])	
	{
		sa(stack_a_ptr);
		ra(stack_a_ptr);
	}
	// 1 0 2
	if (n[0] > n[1] && n[1] < n[2] && n[0] < n[2])
		sa(stack_a_ptr);
	// 1 2 0
	if (n[0] < n[1] && n[1] > n[2] && n[0] > n[2])
		rra(stack_a_ptr);
	// 2 0 1
	if (n[0] > n[1] && n[1] < n[2] && n[0] > n[2])
		ra(stack_a_ptr);
	// 2 1 0
	if (n[0] > n[1] && n[1] > n[2])
	{
		sa(stack_a_ptr);
		rra(stack_a_ptr);
	}
}

void	under_three(t_list **stack_a_ptr)
{
	int	siz;

	siz = ft_lstsize(*stack_a_ptr);
	if (siz <= 1 || check_sorted(stack_a_ptr))
		return ;
	if (siz == 2)
		ra(stack_a_ptr);
	else
		sort_three(stack_a_ptr);
}
