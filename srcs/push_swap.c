/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:20:58 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 23:23:19 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_start(int *numbers, int len)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = init_lst(numbers, len);
	if (check_sorted(&stack_a))
	{
		free(stack_a);
		return ;
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
}

int	ft_ceil(int nbr, int div_num)
{
	if (nbr % div_num == 0)
		return (nbr/div_num);
	return (nbr/div_num + 1);
}

int	divide_stack(t_list **stack_a_ptr, t_list **stack_b_ptr, int prev)
{
	int		cnt;
	int		border1;
	int		border2;

	cnt = ft_lstsize(*stack_a_ptr);
	border1 = prev + ft_ceil(cnt, 3);
	border2 = prev + ft_ceil(cnt, 8);
	while ((*stack_a_ptr) && cnt--)
	{

		if ((*stack_a_ptr)->val < border1)
		{
			pb(stack_a_ptr, stack_b_ptr);
			if ((*stack_a_ptr)->val < border2)
				rb(stack_b_ptr);
		}
		else
			ra(stack_a_ptr);
	}
	return (border1);
}

void	rb_or_rrb(t_list **stack_b_ptr, int target)
{
	t_list	*tmp;
	int 	idx;

	idx = 0;
	tmp = *stack_b_ptr;
	while (tmp->val != target)
	{
		tmp = tmp->next;
		idx++;
	}
	if (idx > ft_lstsize(*stack_b_ptr) / 2)
	{
		while ((*stack_b_ptr)->val != target)
			rrb(stack_b_ptr);
	}
	else
	{
		while ((*stack_b_ptr)->val != target)
			rb(stack_b_ptr);
	}
}

void	push_swap(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	int	nbr;
	int	prev;

	nbr = ft_lstsize(*stack_a_ptr);
	prev = 0;
	while (ft_lstsize(*stack_a_ptr) > 6)
		prev = divide_stack(stack_a_ptr, stack_b_ptr, prev);
	under_six(stack_a_ptr, stack_b_ptr);
	nbr -= ft_lstsize(*stack_a_ptr) + 1;
	while ((*stack_b_ptr))
	{
		rb_or_rrb(stack_b_ptr, nbr--);
		pa(stack_a_ptr, stack_b_ptr);
	}
}
