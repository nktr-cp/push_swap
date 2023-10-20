/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 23:53:48 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/21 04:04:26 by knishiok         ###   ########.fr       */
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

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

char	**parse_args(int argc, char **argv);
void	free_fct(char **ptr);
int	*convert_to_int(char **ptr, int len);
int	ft_strcmp(char *s1, char *s2);
void	compress(int *ptr, int len);
t_dlist	*stack_push(t_dlist *stack, int val);

#endif
