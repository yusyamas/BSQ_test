/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 22:23:43 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/25 23:02:00 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	write_grid(t_grid *grid, char **ans)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->y)
	{
		j = 0;
		while (j <= grid->x)
		{
			write(1, &ans[i][j], 1);
			j++;
		}
		i++;
	}
}

void	decide_grid(t_grid *grid, t_answer *answer, char *text, char **ans)
{
	int	i;
	int	j;
	int	di;
	int	dj;

	i = answer->place / grid->x;
	j = answer->place % grid->x;
	di = 0;
	while (di < answer->length)
	{
		dj = 0;
		while (dj < answer->length)
		{
			ans[i + di][j + dj] = text[3];
			dj++;
		}
		di++;
	}
}

void	init_grid(t_grid *grid, char *text, char **ans)
{
	int	i;
	int	j;

	i = 0;
	while (i < grid->y)
	{
		j = 0;
		while (j <= grid->x)
		{
			if (j == grid->x)
				ans[i][j] = '\n';
			else if (grid->grid[i][j] == 0)
				ans[i][j] = text[1];
			else if (grid->grid[i][j] == 1)
				ans[i][j] = text[2];
			j++;
		}
		i++;
	}
}

void	print_grid(t_grid *grid, t_answer *answer, char *text)
{
	char	**ans;
	int		di;

	ans = malloc(sizeof(char *) * grid->y);
	di = 0;
	while (di < grid->y)
	{
		ans[di] = malloc(sizeof(char) * (grid->x + 1));
		di++;
	}
	init_grid(grid, text, ans);
	decide_grid(grid, answer, text, ans);
	write_grid(grid, ans);
}
