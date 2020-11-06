/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:35:23 by gmoshe            #+#    #+#             */
/*   Updated: 2020/10/05 13:54:32 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"
#include "libft.h"

int		close_p(int game)
{
	game = 0;
	exit(0);
}

void	pars_other(char *line, t_cub *cub)
{
	cub->width = 0;
	cub->height = 0;
	if ((ft_strchr(line, '-')))
		error_output(1);
	mlx_get_screen_size(cub->mlx, &cub->width, &cub->height);
	check_file(line, cub);
	if ((ft_strnstr(line, "R ", 2)))
	{
		while (*line == 'R' || *line == ' ' || *line == '0')
			line++;
		cub->extension_width = ft_atoi(line);
		if (cub->extension_width > cub->width || cub->extension_width < 0)
			cub->extension_width = cub->width;
		while (*line == ' ')
			line++;
		while (*line != ' ')
			line++;
		cub->extension_height = ft_atoi(line);
		if (cub->extension_height > cub->height || cub->extension_height < 0)
			cub->extension_height = cub->height;
	}
	if ((ft_strnstr(line, "F ", 2)))
		ft_color(cub, line);
	if ((ft_strnstr(line, "C ", 2)))
		ft_color(cub, line);
}

void	pars_texture(char *line, t_cub *cub)
{
	char	*texture;
	int		i;

	i = 0;
	while (*line == ' ')
		line++;
	check_file(line, cub);
	while (*line++ != ' ')
		i++;
	while (*line == ' ')
		line++;
	if (!(texture = ft_strtrim(line, " ")))
		error_output(5);
	line = ft_line(line, 0, i);
	line = ft_line(line, 1, i);
	if ((ft_strnstr(line, "NO ", 3)))
		cub->north = texture;
	else if ((ft_strnstr(line, "SO ", 3)))
		cub->south = texture;
	else if ((ft_strnstr(line, "WE ", 3)))
		cub->west = texture;
	else if ((ft_strnstr(line, "EA ", 3)))
		cub->east = texture;
	else if ((ft_strnstr(line, "S ", 2)))
		cub->sprite = texture;
}

void	pars_map(char *line, t_cub *cub)
{
	char	*linemap;
	char	*line2;

	if (!(linemap = ft_strjoin(line, "|\0")))
		error_output(5);
	line2 = cub->map1;
	if (!(cub->map1 = ft_strjoin(cub->map1, linemap)))
		error_output(5);
	free(line2);
	free(linemap);
}

void	parsing(char *line, t_cub *cub)
{
	while (*line == ' ')
		line++;
	if ((ft_strnstr(line, "NO ", 3)) || (ft_strnstr(line, "SO ", 3)) ||
		(ft_strnstr(line, "WE ", 3)) || (ft_strnstr(line, "EA ", 3)) ||
		(ft_strnstr(line, "S ", 2)))
	{
		pars_texture(line, cub);
		return ;
	}
	if ((ft_strnstr(line, "F ", 2)) || (ft_strnstr(line, "C ", 2)) ||
		(ft_strnstr(line, "R ", 2)))
	{
		pars_other(line, cub);
		return ;
	}
	for_egyptians(line, cub);
	if (*line == '1' || *line == '0')
	{
		while (*(line - 1) == ' ')
			line--;
		pars_map(line, cub);
		return ;
	}
	if (line[0])
		error_output(7);
}
