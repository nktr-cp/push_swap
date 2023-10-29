/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:01:57 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 14:32:29 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_preprocess(int *numbers, int len)
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
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		len;
	char	**ptr;

	ptr = parse_args(argc, argv);
	len = get_len(ptr);
	if (len == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	check_args(len, ptr);
	numbers = convert_to_int(ptr, len);
	if (argc == 2)
		free_fct(ptr);
	push_swap_preprocess(numbers, len);
}
