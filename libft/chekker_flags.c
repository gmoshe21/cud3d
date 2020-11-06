/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chekker_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:50:14 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/23 19:34:34 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			shtoch(t_print *s)
{
	if (*s->format_str == '0' && (*(s->format_str + 1) == '*' ||
		(*(s->format_str + 1) >= '1' && *(s->format_str + 1) <= '9')))
		s->shchek = 1;
}

void			miss(t_print *s)
{
	if (*(s->format_str - 1) != '%')
		return ;
	if (*s->format_str == '0' && *(s->format_str + 1) == '-')
		s->x = *(++s->format_str);
	while (*(s->format_str) == '-' && (*(s->format_str + 1) == 'L' ||
		*(s->format_str + 1) == ' ' || *(s->format_str + 1) == 'l' ||
		*(s->format_str + 1) == '#' || *(s->format_str + 1) == 'h' ||
		*(s->format_str + 1) == 'o' || *(s->format_str + 1) == 'f'))
		s->format_str++;
	while (((ft_memchr("lL#$+hfbo ", *s->format_str, 10))))
	{
		s->format_str++;
		s->x = 1;
		s->len = -1;
	}
}

char			*ft_nullwrite(char *str)
{
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

int				str_null(t_print *s)
{
	if (!(s->str = malloc(sizeof(char) * 7)))
		return (0);
	s->str = ft_nullwrite(s->str);
	CHECKSTR((s->newf = ft_strtoch(s->str, s)));
	free(s->str);
	CHECKNEW((s->new = ft_strshir(s->newf, s)));
	write_str(s->new, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}

char			*ft_strshir_c(char *str, t_print *s)
{
	char		*new;
	int			len;
	int			x;

	x = 0;
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
			new[x++] = ' ';
	while (str[len] != '\0')
		new[x++] = str[len++];
	new[x] = '\0';
	free(str);
	return (new);
}
