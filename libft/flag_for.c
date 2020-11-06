/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_for.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 17:48:24 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/23 19:32:20 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			len_str_format(t_print *s)
{
	char	*str;
	int		i;

	i = 0;
	str = s->format_str - 1;
	str++;
	while (*str != '%' && *str)
	{
		i++;
		str++;
	}
	return (i);
}

char		*format_shir(t_print *s)
{
	char	*new;
	int		len;

	len = len_str_format(s);
	if (len < s->sh)
		len = len + ((--s->sh) - len);
	if (!(new = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	if (s->left)
	{
		new[len++] = *(s->format_str);
		while (s->sh--)
			new[len++] = s->s;
	}
	else
	{
		while (s->sh--)
			new[len++] = s->s;
		new[len++] = *(s->format_str);
	}
	while (*s->format_str != '%' && *s->format_str)
		new[len++] = *(s->format_str++);
	new[len] = '\0';
	return (new);
}

void		write_str_for(char *str, t_print *s)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		s->len++;
	}
	free(str);
}

int			write_flag_for(t_print *s)
{
	if (s->shchek && !s->left)
		s->s = '0';
	if (!(s->str = format_shir(s)))
		return (0);
	write_str_for(s->str, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}
