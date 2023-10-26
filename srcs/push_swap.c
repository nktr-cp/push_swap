/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 01:20:58 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 16:46:43 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	push_swap(int *numbers, int len)
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
	under_six(&stack_a, &stack_b);
	// print_stack(stack_a);
}
