/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:43:59 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/25 22:07:46 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	sec_horiz(t_grid *grid, int i, int j, int length)
{
	int	ni;
	int	nj;

	ni = i + length;
	nj = j + length;
	while (nj >= j)
	{
		if (!grid_out_check(grid, ni, nj))
			return (0);
		if (grid->grid[ni][nj] == 1)
			return (0);
		nj--;
	}
	return (1);
}

int	sec_vert(t_grid *grid, int i, int j, int length)
{
	int	ni;
	int	nj;

	ni = i + length;
	nj = j + length;
	while (ni >= i)
	{
		if (!grid_out_check(grid, ni, nj))
			return (0);
		if (grid->grid[ni][nj] == 1)
			return (0);
		ni--;
	}
	return (1);
}

int	square_extend_check(t_grid *grid, int place, int length)
{
	int	i;
	int	j;

	i = place / grid->x;
	j = place % grid->x;
	if (!sec_horiz(grid, i, j, length))
		return (0);
	if (!sec_vert(grid, i, j, length))
		return (0);
	return (1);
}

int	square_length(t_grid *grid, int place)
{
	int	length;

	length = 0;
	while (length <= max(grid->x, grid->y))
	{
		if (!square_extend_check(grid, place, length))
			return (length);
		length++;
	}
	return (length - 1);
}

void	square_search(t_grid *grid, t_answer *ans)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	while (i < grid->y)
	{
		j = 0;
		while (j < grid->x)
		{
			if (grid->grid[i][j] == 0)
			{
				length = square_length(grid, i * grid->x + j);
				if (biggest_square(ans, length, i * grid->x + j))
				{
					ans->length = length;
					ans->place = i * grid->x + j;
				}
			}
			j++;
		}
		i++;
	}
}
