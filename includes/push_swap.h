/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:53:48 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/26 16:48:23 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
// debug
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	int				val;
}	t_list;

char	**parse_args(int argc, char **argv);
void	free_fct(char **ptr);
int		*convert_to_int(char **ptr, int len);
int		ft_strcmp(char *s1, char *s2);
void	compress(int *ptr, int len);

int		ft_stack_swap(t_list **stack);
int		ft_stack_push(t_list **stack_to, t_list **stack_from);
int		ft_stack_rotate(t_list **stack);
int		ft_stack_reverse_rotate(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_a);
int		rrb(t_list **stack_a);

// list utils
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);

// utils
void	print_stack(t_list *lst);
bool	check_sorted(t_list **stack);
t_list	*init_lst(int *numbers, int len);
int		ft_min(int a, int b);

void	under_three(t_list **stack_a_ptr);
void	under_six(t_list **stack_a_ptr, t_list **stack_b_ptr);
void	push_swap(int *numbers, int len);

#endif
