/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusyamas <yuppiy2000@icloud.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:58:47 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/25 21:43:17 by yusyamas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	grid_out_check(t_grid *grid, int i, int j)
{
	if (0 <= j && j < grid->x && 0 <= i && i < grid->y)
		return (1);
	else
		return (0);
}

int	biggest_square(t_answer *ans, int length, int place)
{
	if (length > ans->length)
		return (1);
	else if (length == ans->length && place < ans->place)
		return (1);
	return (0);
}
