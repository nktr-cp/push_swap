/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 09:12:52 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 18:51:12 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **stack_a)
{
	if (ft_stack_swap(stack_a) == 1)
		return (1);
	ft_putendl_fd("sa", STDOUT_FILENO);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (ft_stack_swap(stack_b) == 1)
		return (1);
	ft_putendl_fd("sb", STDOUT_FILENO);
	return (0);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (ft_stack_swap(stack_a) || ft_stack_swap(stack_b))
		return (1);
	ft_putendl_fd("ss", STDOUT_FILENO);
	return (0);
}

int	pa(t_list **stack_a, t_list **stack_b)
{
	if (ft_stack_push(stack_a, stack_b))
		return (1);
	ft_putendl_fd("pa", STDOUT_FILENO);
	return (0);
}

int	pb(t_list **stack_a, t_list **stack_b)
{
	if (ft_stack_push(stack_b, stack_a))
		return (1);
	ft_putendl_fd("pb", STDOUT_FILENO);
	return (0);
}
