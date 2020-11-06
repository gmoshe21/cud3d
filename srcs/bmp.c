/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 18:10:13 by gmoshe            #+#    #+#             */
/*   Updated: 2020/10/12 17:01:29 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cub.h"

void		check_file(char *line, t_cub *cub)
{
	if ((ft_strnstr(line, "NO ", 3)) && cub->north)
		error_output(7);
	else if ((ft_strnstr(line, "SO ", 3)) && cub->south)
		error_output(7);
	else if ((ft_strnstr(line, "WE ", 3)) && cub->west)
		error_output(7);
	else if ((ft_strnstr(line, "EA ", 3)) && cub->east)
		error_output(7);
	else if ((ft_strnstr(line, "S ", 2)) && cub->sprite)
		error_output(7);
	else if ((ft_strnstr(line, "R ", 2)) && cub->extension_width)
		error_output(7);
	else if ((ft_strnstr(line, "F ", 2)) && cub->floor != -1)
		error_output(7);
	else if ((ft_strnstr(line, "C ", 2)) && cub->ceilling != -1)
		error_output(7);
	else if (cub->map1[0])
		error_output(7);
}

void		scrin_bmp2(t_cub *cub, int32_t num, char *bmp)
{
	uint32_t	i;
	int			y;

	num = 1;
	ft_memcpy(&bmp[26], &num, 2);
	ft_memcpy(&bmp[28], &cub->pixel, 2);
	i = 54;
	y = 0;
	while (y < cub->extension_height)
	{
		ft_memcpy(&bmp[i], cub->add, cub->extension_width * sizeof(int));
		cub->add += cub->length;
		i += cub->extension_width * sizeof(int);
		y++;
	}
	num = open("scr.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0666);
	write(num, bmp, i);
	free(bmp);
	close(num);
	exit(0);
}

void		scrin_bmp(t_cub *cub)
{
	char			*bmp;
	int32_t			num;
	uint32_t		size;

	size = (cub->extension_height * cub->extension_width + 54) * sizeof(int);
	if (!(bmp = (char*)malloc(size)))
		error_output(5);
	ft_bzero(bmp, size);
	ft_memcpy(&bmp[0], "BM", 2);
	ft_memcpy(&bmp[2], &size, 4);
	num = 54;
	ft_memcpy(&bmp[10], &num, 4);
	num = 40;
	ft_memcpy(&bmp[14], &num, 4);
	num = cub->extension_width;
	ft_memcpy(&bmp[18], &num, 4);
	num = -(cub->extension_height);
	ft_memcpy(&bmp[22], &num, 4);
	scrin_bmp2(cub, num, bmp);
}
