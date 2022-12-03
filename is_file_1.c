/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: kkengo <kkengo@student.42tokyo.jp>         +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2022/10/25 02:59:21 by kkengo            #+#    #+#             */
/*   Updated: 2022/10/25 02:59:21 by kkengo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	get_char_count_from_file(char *filename)
{
	int		fd;
	int		cnt;
	char	c;

	cnt = 0;
	c = ' ';
	fd = open(filename, O_RDONLY);
	while (true)
	{
		if (read(fd, &c, 1) == 0)
			break ;
		cnt++;
	}
	close(fd);
	return (cnt);
}

char	*get_raw_str(char *filename)
{
	char	*str;
	char	c;
	int		cnt;
	int		fd;
	int		i;

	cnt = get_char_count_from_file(filename);
	str = malloc(sizeof(char) * (cnt + 1));
	fd = open(filename, O_RDONLY);
	i = 0;
	while (i < cnt)
	{
		if (read(fd, &c, 1) == 0)
			break ;
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

int	get_row_count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}
