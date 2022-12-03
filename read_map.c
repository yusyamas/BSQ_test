/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkengo <kkengo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:06:23 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/26 22:01:12 by kkengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*two_str(char *str, int *row, int *col)
{
	int	i;
	int	**grid;

	i = 0;
	while (str[i] != '\n')
		i++;
	str += i + 1;
	return (str);
}
int	**read_map(char *str, int *row, int *col, int place)
{
	int	i;
	int	**grid;

	grid = (int **)malloc(sizeof(int *) * (*col));
	i = -1;
	while (++i < (*col))
		grid[i] = malloc(sizeof(int) * (*row));
	str = two_str(str, row, col);
	place = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(32 <= str[i] && str[i] <= 126))
		{
			i++;
			continue ;
		}
		if (str[i] == '.')
			grid[place / (*row)][place % (*row)] = 0;
		if (str[i] == 'o')
			grid[place / (*row)][place % (*row)] = 1;
		i++;
		place++;
	}
	return (grid);
}
