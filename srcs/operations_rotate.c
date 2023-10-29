/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 10:01:48 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 14:03:08 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_list **stack_a, bool out)
{
	if (ft_stack_rotate(stack_a))
		return (1);
	if (out)
		ft_putendl_fd("ra", STDOUT_FILENO);
	return (0);
}

int	rb(t_list **stack_b, bool out)
{
	if (ft_stack_rotate(stack_b))
		return (1);
	if (out)
		ft_putendl_fd("rb", STDOUT_FILENO);
	return (0);
}

int	rr(t_list **stack_a, t_list **stack_b, bool out)
{
	if (ft_stack_rotate(stack_a) || ft_stack_rotate(stack_b))
		return (1);
	if (out)
		ft_putendl_fd("rr", STDOUT_FILENO);
	return (0);
}
