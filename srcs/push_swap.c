/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:20:58 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/24 21:31:53 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_three(int *n, t_list **stack_a_ptr)
{
	n[0] = (*stack_a_ptr)->val;
	n[1] = (*stack_a_ptr)->next->val;
	n[2] = (*stack_a_ptr)->next->next->val;
}

void	sort_three(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	int	n[3];

	init_three(n, stack_a_ptr);
	
}

void	under_three(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	int	siz;

	siz = ft_lstsize(*stack_a_ptr);
	if (siz <= 1 || check_sorted(stack_a_ptr))
		return ;
	if (siz == 2)
		ra(stack_a_ptr);
	else
		sort_three(stack_a_ptr, stack_b_ptr);
}

// for debug (must be deleted)
void	print_stack(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%d\n", tmp->val);
		tmp = tmp->next;
	}
}

void	push_swap(int *numbers, int len)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = init_lst(numbers, len);
	if (!check_sorted(&stack_a))
	{
		free(stack_a);
		return ;
	}
	stack_b = NULL;
}
