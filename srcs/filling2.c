/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:07:16 by gmoshe            #+#    #+#             */
/*   Updated: 2020/09/25 17:08:14 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

char	*ft_line(char *line, int x, int i)
{
	if (x == 0)
		while (*(line - 1) == ' ')
			line--;
	if (x == 1)
		while (i-- != 0)
			line--;
	return (line);
}

void	m_error(void)
{
	write(1, "Error\nnot valid map", 19);
	exit(0);
}

void	c_walls(char **map, int x, int y, int i)
{
	int	j;

	j = ft_strlen(map[x]);
	if (x < 0 || x >= i || y < 0 || y >= j)
		m_error();
	if (map[x][y] == '1' || map[x][y] == '0' || map[x][y] == ' '
		|| map[x][y] == '2')
		return ;
	if (map[x][y] == '3')
		map[x][y] = '0';
	c_walls(map, x, y + 1, i);
	c_walls(map, x, y - 1, i);
	c_walls(map, x + 1, y, i);
	c_walls(map, x - 1, y, i);
}

int		fill(t_cub *cub, int x, int y)
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
	c_walls(cub->map, x, y, i);
	return (0);
}

void	filling3(t_cub *cub)
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
			cub->map[y][x] = '3';
			fill(cub, y, x);
			cub->map[y][x] = f;
			break ;
		}
		y++;
	}
}
