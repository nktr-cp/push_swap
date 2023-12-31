/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:53:48 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 14:30:59 by knishiok         ###   ########.fr       */
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
	int				idx;
	int				val;
	int				cost_a;
	int				cost_b;
	int				target_idx;
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
int		sa(t_list **stack_a, bool out);
int		sb(t_list **stack_b, bool out);
int		ss(t_list **stack_a, t_list **stack_b, bool out);
int		pa(t_list **stack_a, t_list **stack_b, bool out);
int		pb(t_list **stack_a, t_list **stack_b, bool out);
int		ra(t_list **stack_a, bool out);
int		rb(t_list **stack_b, bool out);
int		rr(t_list **stack_a, t_list **stack_b, bool out);
int		rra(t_list **stack_a, bool out);
int		rrb(t_list **stack_b, bool out);
int		rrr(t_list **stack_a, t_list **stack_b, bool out);

int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

void	check_args(int len, char **argv);
int		get_len(char **ptr);
bool	check_sorted(t_list **stack);
t_list	*init_lst(int *numbers, int len);
int		ft_min(int a, int b);
int		ft_abs(int nbr);

void	do_optimized_rotation(t_list **stack_a_ptr, t_list **stack_b_ptr,
			int cost_a, int cost_b);

void	init_stacks(t_list **stack_a_ptr, t_list **stack_b_ptr);
void	init_index(t_list *stack_a, t_list *stack_b);
int		update_target_index(t_list *stack_a, t_list *stack_b);
void	initialize_cost(t_list *stack_a, t_list *stack_b);
void	update_target_index_b_largest(t_list *stack_a, t_list *stack_b,
			int value);

void	under_three(t_list **stack_a_ptr);
void	under_six(t_list **stack_a_ptr, t_list **stack_b_ptr);
void	push_swap_preprocess(int *numbers, int len);
void	do_optimized_rotation(t_list **stack_a_ptr, t_list **stack_b_ptr,
			int cost_a, int cost_b);
void	push_swap(t_list **stack_a_ptr, t_list **stack_b_ptr);

#endif
