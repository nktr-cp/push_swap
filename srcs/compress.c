/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 04:07:51 by knishiok          #+#    #+#             */
/*   Updated: 2023/10/29 16:03:47 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*duplicate_numbers(int *ptr, int len)
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int) * len);
	if (res == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < len)
	{
		res[i] = ptr[i];
		i++;
	}
	return (res);
}

int	*sorted(int *ptr, int len)
{
	int	i;
	int	j;
	int	tmp;
	int	*res;

	res = duplicate_numbers(ptr, len);
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (res[i] > res[j])
			{
				tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (res);
}

void	compress(int *ptr, int len)
{
	int	*sorted_numbers;
	int	i;
	int	j;

	i = 0;
	sorted_numbers = sorted(ptr, len);
	while (i < len)
	{
		j = 0;
		while (ptr[i] != sorted_numbers[j])
			j++;
		ptr[i] = j + 1;
		i++;
	}
	free(sorted_numbers);
}
