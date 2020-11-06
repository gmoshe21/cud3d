/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:30:43 by gmoshe            #+#    #+#             */
/*   Updated: 2020/09/30 16:00:27 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	map_error(void)
{
	write(1, "Error\nnot valid map", 19);
	exit(0);
}

void	check_walls(char **map, int x, int y, int i)
{
	int	j;

	if (map[x] && !(x < 0))
		j = ft_strlen(map[x]);
	else
		return ;
	if (x < 0 || x >= i || y < 0 || y >= j)
		map_error();
	if (map[x][y] == '1' || map[x][y] == '3' || map[x][y] == ' '
		|| map[x][y] == '2' || !map[x][y])
		return ;
	if (map[x][y] == '0')
		map[x][y] = '3';
	check_walls(map, x, y + 1, i);
	check_walls(map, x, y - 1, i);
	check_walls(map, x + 1, y, i);
	check_walls(map, x - 1, y, i);
}

int		filling2(t_cub *cub, int x, int y)
{
	int i;
	int j;
	int max;

	i = 0;
	j = 0;
	max = j;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j])
			j++;
		if (max < j)
			max = j;
		i++;
	}
	if (x == 0)
		error_output(4);
	check_walls(cub->map, x, y, i);
	return (0);
}

void	filling(t_cub *cub)
{
	int		x;
	int		y;
	char	f;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			f = cub->map[y][x];
			if (f == 'N' || f == 'S' || f == 'W' || f == 'E')
				break ;
			x++;
		}
		if (f == 'N' || f == 'S' || f == 'W' || f == 'E')
		{
			cub->map[y][x] = '0';
			filling2(cub, y, x);
			cub->map[y][x] = f;
			break ;
		}
		y++;
	}
}
