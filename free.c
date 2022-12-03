/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:30:18 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/26 19:43:43 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	free_grid(t_grid *grid)
{
	int	i;

	i = 0;
	while (i < grid->y)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
}

void	free_state(t_grid *grid)
{
	free_grid(grid);
}
