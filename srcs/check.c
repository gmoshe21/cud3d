/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:43:20 by gmoshe            #+#    #+#             */
/*   Updated: 2020/09/30 16:17:57 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	for_monkeys(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == ',')
			i++;
		str++;
	}
	if (i != 2)
		error_output(3);
}

void	valid_floor_ceilling(char **str)
{
	int		i;
	char	*s;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) > 255 || ft_atoi(str[i]) < 0)
			error_output(3);
		i++;
	}
	if (i != 3)
		error_output(3);
	if ((s = ft_strchr(str[i - 1], ' ')))
	{
		while (*s)
		{
			if (*s != ' ')
				error_output(3);
			s++;
		}
	}
}

void	valid_map(t_cub *cub)
{
	int		x;
	int		y;
	char	z;
	int		poz;

	y = -1;
	poz = 0;
	if (cub->map == NULL)
		error_output(5);
	while (cub->map[++y])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			z = cub->map[y][x];
			if (z != ' ' && z != '1' && z != '0' && z != '2' && z != 'N'
				&& z != 'W' && z != 'E' && z != 'S')
				error_output(4);
			if (z == 'W' || z == 'S' || z == 'E' || z == 'N')
				poz++;
		}
	}
	if (poz != 1)
		error_output(4);
}

void	check2(t_cub *cub, int x, int y)
{
	filling(cub);
	if ((cub->map[0][x] == '3' || cub->map[0][x] == '2'))
		error_output(4);
	if ((cub->map[y][x] == '3' || cub->map[y][x] == '2')
		&& (cub->map[y][x + 1] == '0' || cub->map[y][x - 1] == '0'
		|| cub->map[y + 1][x] == '0' || cub->map[y - 1][x] == '0'))
		error_output(4);
	if ((cub->map[y][x] == '3' || cub->map[y][x] == '2')
		&& (!cub->map[y][x + 1] || !cub->map[y][x - 1]
		|| !cub->map[y + 1][x] || !cub->map[y - 1][x]))
		error_output(4);
}

int		check(t_cub *cub)
{
	int		x;
	int		y;

	y = -1;
	valid_map(cub);
	while (cub->map[++y + 1])
	{
		x = -1;
		while (cub->map[y][++x])
		{
			check2(cub, x, y);
			if ((cub->map[y][x] == '3' || cub->map[y][x] == '2')
				&& (cub->map[y][x + 1] == ' ' || cub->map[y][x - 1] == ' '
				|| cub->map[y + 1][x] == ' ' || cub->map[y - 1][x] == ' '))
				return (0);
		}
	}
	x = -1;
	while (cub->map[y][++x])
		if (cub->map[y][x] != ' ' && cub->map[y][x] != '1'
			&& cub->map[y][x] != '0')
			return (0);
	filling3(cub);
	my_map(cub);
	return (1);
}
