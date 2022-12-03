/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkengo <kkengo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 08:56:53 by yusyamas          #+#    #+#             */
/*   Updated: 2022/10/26 22:13:44 by kkengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define FT_NULL '\0'

typedef struct s_answer
{
	int	place;
	int	length;
}		t_answer;
typedef struct s_grid
{
	int	**grid;
	int	x;
	int	y;
}		t_grid;

int		max(int a, int b);
int		grid_out_check(t_grid *grid, int i, int j);
int		square_length(t_grid *grid, int place);
void	square_search(t_grid *grid, t_answer *ans);
int		biggest_square(t_answer *ans, int length, int place);
int		square_extend_check(t_grid *grid, int place, int length);
int		sec_vert(t_grid *grid, int i, int j, int length);
int		sec_horiz(t_grid *grid, int i, int j, int length);
void	decide_grid(t_grid *grid, t_answer *answer, char *text, char **ans);
void	init_grid(t_grid *grid, char *text, char **ans);
void	print_grid(t_grid *grid, t_answer *answer, char *text);
void	write_grid(t_grid *grid, char **ans);
void	free_state(t_grid *grid);
void	free_grid(t_grid *grid);
void	input_one(int place);
void	input_two(int argc, char **argv, int place);
int		**read_map(char *str, int *row, int *col, int place);
int		get_char_count_from_file(char *filename);
char	*get_raw_str(char *filename);
int		get_line_count(char *str);
int		get_row_count(char *str);
char	*get_row(char *str, int *low, int *col);
int		is_file(char *filename, int *row, int *col);

#endif
