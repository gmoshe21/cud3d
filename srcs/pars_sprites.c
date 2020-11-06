/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 14:50:50 by gmoshe            #+#    #+#             */
/*   Updated: 2020/10/05 13:41:26 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void	for_egyptians(char *line, t_cub *cub)
{
	static int	i;

	if (cub->map1[0] && line[0] == '\0')
		i = 1;
	if ((*line == '1' || *line == '0') && i == 1)
		error_output(7);
}

void	pars_sprit2(t_cub *cub)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	i = 0;
	while (cub->map[j])
	{
		k = 0;
		while (cub->map[j][k])
		{
			if (cub->map[j][k] == '2')
			{
				cub->sp[i][0] = j;
				cub->sp[i][1] = k;
				i++;
			}
			k++;
		}
		j++;
	}
}

void	pars_sprit(t_cub *cub, int z)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '2')
				cub->spnum++;
			x++;
		}
		y++;
	}
	y = -1;
	if (cub->spnum > 10)
		error_output(4);
	else if (!(cub->sp = malloc(sizeof(int) * z)))
		error_output(5);
	while (y++ < cub->spnum)
		if (!(cub->sp[y] = malloc(sizeof(int) * 2)))
			error_output(5);
	pars_sprit2(cub);
}

void	my_map(t_cub *cub)
{
	int		x;
	int		y;
	char	f;

	y = 0;
	while (*cub->map[y])
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
			position(cub, x, y);
			break ;
		}
		y++;
	}
	pars_sprit(cub, x);
}
