/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 00:01:57 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/24 20:49:19 by knishiok         ###   ########.fr       */
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

int	get_len(char **ptr)
{
	int	len;

	len = 0;
	while (ptr[len])
		len++;
	return (len);
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
	// check_sorted(numbers, len);
	push_swap(numbers, len);
}
