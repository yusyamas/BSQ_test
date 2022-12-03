/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkengo <kkengo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 02:59:39 by kkengo            #+#    #+#             */
/*   Updated: 2022/10/26 22:14:10 by kkengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	input_one(int place)
{
	int			i;
	char		*filename;
	t_grid		panel;
	t_answer	ans;
	char		*str;

	filename = malloc(sizeof(char) * 32);
	read(0, filename, 32);
	i = 0;
	while (filename[i] != '\n')
		i++;
	filename[i] = '\0';
	if (is_file(filename, &panel.x, &panel.y))
	{
		str = get_raw_str(filename);
		panel.grid = read_map(str, &panel.x, &panel.y, place);
		ans.place = panel.x * panel.y;
		ans.length = 0;
		square_search(&panel, &ans);
		print_grid(&panel, &ans, str);
		free_state(&panel);
	}
	else
		write(1, "map error\n", 10);
	i++;
}

void	input_two(int argc, char **argv, int place)
{
	int			i;
	char		*filename;
	t_grid		panel;
	t_answer	ans;
	char		*str;

	i = 1;
	while (i < argc)
	{
		filename = argv[i];
		if (is_file(filename, &panel.x, &panel.y))
		{
			str = get_raw_str(filename);
			panel.grid = read_map(str, &panel.x, &panel.y, place);
			ans.place = panel.x * panel.y;
			ans.length = 0;
			square_search(&panel, &ans);
			print_grid(&panel, &ans, str);
			free_state(&panel);
		}
		else
			write(1, "map error\n", 10);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	place;

	if (argc == 1)
		input_one(place);
	else if (argc >= 2)
		input_two(argc, argv, place);
	return (0);
}
