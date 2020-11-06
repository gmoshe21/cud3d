/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 02:50:45 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/23 19:36:42 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strdup(const char *str)
{
	char	*str_2;
	int		i;

	i = 0;
	str_2 = (char*)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!(str_2))
		return (NULL);
	while (str[i])
	{
		str_2[i] = str[i];
		i++;
	}
	str_2[i] = '\0';
	return (str_2);
}

void		intnull(t_print *s)
{
	if (s->sh && s->tchek && !s->t)
	{
		s->st = ' ';
	}
	if (s->tchek && !s->t && s->sint != 0)
		s->tchek = 0;
}
