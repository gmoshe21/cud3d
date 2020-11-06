/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:22:16 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/10 04:07:36 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*write_format_str(t_print *s)
{
	while (*s->format_str != '%' && *s->format_str)
	{
		write(1, &(*s->format_str), 1);
		s->format_str++;
		s->len++;
	}
	return (s->format_str);
}

int		params_format(t_print *s)
{
	s->first_s = 0;
	while (*s->format_str)
	{
		if (*s->format_str != '%' && *s->format_str && !s->first_s)
			s->format_str = write_format_str(s);
		if (*s->format_str == '%' && *s->format_str)
		{
			s->first_s = 1;
			while (s->first_s)
			{
				checker(s);
				ERROR(s->len);
			}
		}
		ERROR(s->len);
	}
	return (s->len);
}

int		ft_printf(const char *format, ...)
{
	t_print	s;
	int		result;

	s.len = 0;
	if (format == NULL)
		return (-1);
	s.format_str = (char*)format;
	va_start(s.pi, format);
	result = params_format(&s);
	va_end(s.pi);
	return (result);
}
