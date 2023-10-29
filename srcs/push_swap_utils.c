/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:28:59 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 16:04:33 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_args(int len, char **argv)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (argv[i][j] == '\0')
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j++]))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				exit(EXIT_FAILURE);
			}
		}
	}
}

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
		if (new == NULL)
			exit(EXIT_FAILURE);
		new->val = numbers[i];
		new->next = NULL;
		ft_lstadd_back(&lst, new);
		i++;
	}
	free(numbers);
	return (lst);
}

int	get_len(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
}
