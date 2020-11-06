/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 19:04:26 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/22 19:48:01 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strshir(char *str, t_print *s)
{
	char	*new;
	int		len;
	int		x;

	x = 0;
	s->strlen = ft_strlen(str);
	if (!s->sh)
		len = s->strlen;
	if (s->strlen < s->sh)
		len = s->sh;
	else if (s->sh)
		len = s->strlen;
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	if (s->strlen < s->sh && s->sh)
		while (x < s->sh - s->strlen)
			new[x++] = s->s;
	while (str[len] != '\0')
		new[x++] = str[len++];
	new[x] = '\0';
	free(str);
	return (new);
}

char		*ft_strtoch(char *str, t_print *s)
{
	char	*new;
	int		i;

	i = 0;
	if (s->t == 0 && s->tchek == 0)
		return (ft_strdup(str));
	if (s->t == 0 && s->tchek)
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (0);
		new[0] = '\0';
		return (new);
	}
	if (!(new = malloc(sizeof(char) * (s->t + 1))))
		return (0);
	else
		while (s->t--)
		{
			new[i] = str[i];
			i++;
		}
	new[i] = '\0';
	return (new);
}

char		*ft_strtoch_int(char *str, t_print *s)
{
	char	*new;

	s->x_zn = 0;
	s->int_x = 0;
	s->strlen = ft_strlen(str);
	if (!s->t)
		return (ft_strdup(str));
	if (s->strlen < s->t || (s->strlen == s->t && *str == '-'))
		s->int_len = s->t;
	else
		s->int_len = s->strlen;
	if (s->int_len == s->t && *str == '-')
		s->int_len++;
	if (!(new = malloc(sizeof(char) * (s->int_len + 1))))
		return (0);
	if ((s->strlen < s->t || s->strlen == s->t) && *str == '-' && !s->x_zn++)
		new[s->int_x++] = '-';
	s->int_len = s->int_x;
	if (s->strlen < s->t || (s->strlen == s->t && *str == '-'))
		while (s->int_x - s->x_zn < s->t - (s->strlen - s->x_zn))
			new[s->int_x++] = s->st;
	while (str[s->int_len])
		new[s->int_x++] = str[s->int_len++];
	new[s->int_x] = '\0';
	return (new);
}

void		write_str(char *str, t_print *s)
{
	int		i;

	i = 0;
	if (s->left == 1)
		while (s->sh > s->strlen && i < (s->sh - s->strlen))
			i++;
	while (str[i] != '\0')
	{
		write(1, &(str[i++]), 1);
		s->len++;
	}
	i = 0;
	while (s->left && s->sh > s->strlen && i < (s->sh - s->strlen))
	{
		write(1, &(str[i++]), 1);
		s->len++;
	}
	free(str);
}
