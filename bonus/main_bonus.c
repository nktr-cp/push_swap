/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 21:52:43 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 14:18:52 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	process_moves(t_list **stack_a_ptr, t_list **stack_b_ptr, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		sa(stack_a_ptr, false);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(stack_a_ptr, false);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(stack_a_ptr, stack_b_ptr, false);
	else if (ft_strcmp(str, "pa\n") == 0)
		pa(stack_a_ptr, stack_b_ptr, false);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(stack_a_ptr, stack_b_ptr, false);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(stack_a_ptr, false);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(stack_b_ptr, false);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(stack_a_ptr, stack_b_ptr, false);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(stack_a_ptr, false);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(stack_b_ptr, false);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(stack_a_ptr, stack_b_ptr, false);
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	read_moves(t_list **stack_a_ptr, t_list **stack_b_ptr)
{
	char	*line;

	while (1)
	{
		line = get_next_line(STDOUT_FILENO);
		if (line == NULL)
			break ;
		if (process_moves(stack_a_ptr, stack_b_ptr, line) == EXIT_FAILURE)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			free(line);
			return (EXIT_FAILURE);
		}
		free(line);
	}
	return (EXIT_SUCCESS);
}

void	judge_fct_preprocess(int *numbers, int len)
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
	if (read_moves(&stack_a, &stack_b) == EXIT_SUCCESS)
	{
		if (stack_b == NULL && check_sorted(&stack_a))
			ft_putstr_fd("OK\n", STDOUT_FILENO);
		else
			ft_putstr_fd("KO\n", STDOUT_FILENO);
	}
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
	judge_fct_preprocess(numbers, len);
}
