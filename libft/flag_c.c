/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 14:16:26 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/23 16:29:11 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					write_flag_c(t_print *s)
{
	char			c;

	c = va_arg(s->pi, int);
	if (!(s->str = malloc(sizeof(char) * 2)))
		return (0);
	s->str[0] = c;
	s->str[1] = '\0';
	s->strlen = 1;
	CHECKSTR((s->new = ft_strshir_c(s->str, s)));
	if ((!c && s->strlen && s->left))
		if (++s->len)
			write(1, &c, 1);
	write_str(s->new, s);
	if ((!c && !s->len) || (!c && s->strlen && !s->left))
	{
		write(1, &c, 1);
		s->len++;
	}
	s->format_str++;
	s->first_s = 0;
	return (1);
}

int					write_flag_s(t_print *s)
{
	char			*str;

	str = va_arg(s->pi, char*);
	if (s->shchek && !s->left)
		s->s = '0';
	if (str == NULL)
	{
		s->i = (str_null(s));
		return (s->i);
	}
	s->strlen = ft_strlen(str);
	CHECKSTR((s->newf = ft_strtoch(str, s)));
	CHECKNEW((s->new = ft_strshir(s->newf, s)));
	write_str(s->new, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}

int					write_flag_integ(t_print *s)
{
	int				i;

	i = va_arg(s->pi, int);
	CHECK((s->str = ft_itoa(i)));
	s->sint = i;
	intnull(s);
	s->strlen = ft_strlen(s->str);
	CHECKSTR((s->newf = ft_strtoch_int(s->str, s)));
	free(s->str);
	if (s->tchek && !s->t)
		s->newf[0] = '\0';
	if (s->shchek && !s->left && !s->t && s->st != ' ')
	{
		if (i > 0 || (i == 0 && s->shchek && s->sh))
			s->sh++;
		s->t = --s->sh;
		CHECKNEW((s->new = ft_strtoch_int(s->newf, s)));
		free(s->newf);
	}
	else
		CHECKNEW((s->new = ft_strshir(s->newf, s)));
	write_str(s->new, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}

int					write_flag_u(t_print *s)
{
	unsigned int	i;

	i = va_arg(s->pi, unsigned int);
	CHECK((s->str = ft_itoa_u(i)));
	if (s->shchek && !s->tchek)
		s->s = '0';
	s->strlen = ft_strlen(s->str);
	CHECKSTR((s->newf = ft_strtoch_int(s->str, s)));
	free(s->str);
	if (s->tchek && !s->t && *s->newf == '0')
		s->newf[0] = '\0';
	CHECKNEW((s->new = ft_strshir(s->newf, s)));
	write_str(s->new, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}
