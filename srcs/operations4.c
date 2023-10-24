/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:02:09 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/24 20:43:33 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_list **stack_a)
{
	if (ft_stack_reverse_rotate(stack_a))
		return (1);
	ft_putendl_fd("rra", STDOUT_FILENO);
	return (0);
}

int	rrb(t_list **stack_b)
{
	if (ft_stack_reverse_rotate(stack_b))
		return (1);
	ft_putendl_fd("rrb", STDOUT_FILENO);
	return (0);
}

int	rrr(t_list **stack_a, t_list **stack_b)
{
	if (ft_stack_reverse_rotate(stack_a) || ft_stack_reverse_rotate(stack_b))
		return (1);
	ft_putendl_fd("rrr", STDOUT_FILENO);
	return (0);
}
