/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 16:15:10 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/23 19:27:48 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			shir(t_print *s)
{
	s->s = ' ';
	if (*s->format_str == '0')
		shtoch(s);
	if (*s->format_str == '0' && *(s->format_str + 1) == '*')
	{
		s->format_str++;
	}
	if (*s->format_str == '*')
	{
		s->sh = va_arg(s->pi, int);
		s->format_str++;
	}
	else
	{
		if (*(s->format_str) >= '0' && *(s->format_str) <= '9')
			s->sh = *(s->format_str++) - '0';
		while (*(s->format_str) >= '0' && *(s->format_str) <= '9')
			s->sh = (s->sh * 10) + (*(s->format_str++) - '0');
	}
	if (s->sh < 0)
	{
		s->sh = s->sh * (-1);
		s->left = 1;
	}
	s->x = *(s->format_str);
}

void			toch(t_print *s)
{
	s->tchek = 1;
	s->st = '0';
	if (*(++s->format_str) == '*')
	{
		s->t = va_arg(s->pi, int);
		s->format_str++;
	}
	else
	{
		if (*(s->format_str) >= '0' && *(s->format_str) <= '9')
			s->t = *(s->format_str++) - '0';
		while (*(s->format_str) >= '0' && *(s->format_str) <= '9')
		{
			s->t = (s->t * 10) + (*(s->format_str++) - '0');
		}
	}
	if (s->t < 0)
	{
		s->t = 0;
		s->tchek = 0;
	}
	s->x = *(s->format_str);
}

void			chek_params(t_print *s)
{
	s->i = 1;
	if (s->x == 'c')
		s->i = write_flag_c(s);
	else if (s->x == 's')
		s->i = write_flag_s(s);
	else if (s->x == 'i' || s->x == 'd')
		s->i = write_flag_integ(s);
	else if (s->x == 'u')
		s->i = write_flag_u(s);
	else if (s->x == 'x' || s->x == 'X')
		s->i = write_flag_x(s);
	else if (s->x == 'p')
		s->i = write_flag_p(s);
	else if (s->x == '%')
		s->i = write_flag_for(s);
	if (s->i <= 0)
	{
		free_str(s);
		s->len = -1;
	}
}

void			free_str(t_print *s)
{
	if (s->i == -1)
		free(s->str);
	if (s->i == -2)
		free(s->newf);
}

void			checker(t_print *s)
{
	s->sh = 0;
	s->left = 0;
	s->t = 0;
	s->tchek = 0;
	s->st = '0';
	s->x = *(++s->format_str);
	s->shchek = 0;
	miss(s);
	if (s->x == '-' || ((s->x >= '0' && s->x <= '9') || s->x == '*')
			|| s->x == '.')
	{
		while (s->x == '-')
		{
			s->left = 1;
			s->x = *(++s->format_str);
		}
		if ((s->x >= '0' && s->x <= '9') || s->x == '*')
			shir(s);
		if (s->x == '.')
			toch(s);
	}
	if ((ft_memchr("csiduxXp%", s->x, 9)))
		chek_params(s);
	if (s->len == -1)
		return ;
}
