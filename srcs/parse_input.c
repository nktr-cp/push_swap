/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 02:01:50 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/21 04:21:01 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_valid_range(char **ptr)
{
	int		i;
	long	nbr;

	i = 0;
	while (ptr[i])
	{
		nbr = ft_atoi(ptr[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
		{
			ft_putstr_fd("Error\n", STDERR_FILENO);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	has_unique_values(char **ptr)
{
	int		i;
	int		j;

	i = 0;
	while (ptr[i])
	{
		j = i + 1;
		while (ptr[j])
		{
			if (ft_strcmp(ptr[i], ptr[j]) == 0)
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

void	free_fct(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		free(ptr[i++]);
	free(ptr);
}

int	*convert_to_int(char **ptr, int len)
{
	int	i;
	int	*res;

	res = (int *)malloc(len * sizeof(int));
	i = -1;
	while (++i < len)
		res[i] = (int)ft_atoi(ptr[i]);
	compress(res, len);
	return (res);
}

char	**parse_args(int argc, char **argv)
{
	char	**ptr;

	if (argc < 2)
		exit(STDERR_FILENO);
	if (argc == 2)
	{
		ptr = ft_split((char const *)(argv[1]), ' ');
		if (ptr == NULL)
			exit(EXIT_FAILURE);
	}
	else
		ptr = argv + 1;
	if (!is_valid_range(ptr) || !(has_unique_values(ptr)))
	{
		if (argc == 2)
			free_fct(ptr);
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
