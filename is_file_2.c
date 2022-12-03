/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkengo <kkengo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:17:40 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/26 21:21:24 by kkengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	put_error(char *str, int *row, int column_count)
{
	if (*row != column_count)
	{
		write(1, "map error\n", 10);
		exit(0);
	}
}

void	check_row(char *str, int *row, int *col)
{
	int	i;
	int	line_count;
	int	column_count;

	i = 0;
	column_count = 0;
	line_count = 0;
	while (str[i] != '\0')
	{
		if (32 <= str[i] && str[i] <= 126)
			column_count++;
		if (str[i] == '\n')
		{
			if (line_count == 0)
				*row = column_count;
			if (line_count != 0)
				put_error(str, row, column_count);
			line_count++;
			column_count = 0;
		}
		i++;
	}
	*col = line_count;
}

char	*get_row(char *str, int *row, int *col)
{
	int		i;
	int		line_count;
	int		column_count;
	char	*str_row;
	int		column;

	str_row = malloc(sizeof(char) * 5);
	i = 0;
	while (i < 4)
	{
		str_row[i] = str[i];
		i++;
	}
	str_row[i] = '\0';
	while (*str != '\n')
		str++;
	str++;
	check_row(str, row, col);
	return (str_row);
}

int	is_file(char *filename, int *row, int *col)
{
	char	*str;
	char	*str_row;
	int		i;

	str = get_raw_str(filename);
	str_row = get_row(str, row, col);
	if (!(str_row[0] >= '0' && str_row[0] <= '9'))
	{
		write(1, "map error\n", 10);
		exit(0);
	}
	if (str_row[1] == str_row[2] || str_row[1] == str_row[3]
		|| str_row[2] == str_row[3])
	{
		write(1, "map error\n", 10);
		exit(0);
	}
	return (1);
}
