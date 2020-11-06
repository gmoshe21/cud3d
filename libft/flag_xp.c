/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_xp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 15:27:47 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/10 04:06:16 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					len_x(unsigned int n)
{
	int				i;

	i = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char				*write_x(unsigned int n, t_print *s)
{
	char			*str;
	int				len;
	unsigned int	chek;

	len = len_x(n) - 1;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len--] = '\0';
	chek = n % 16;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		if (chek > 9 && chek < 16)
			str[len] = chek + ((s->chek_flag_x - ('x' - 'a')) - 10);
		else if (chek < 10)
			str[len] = chek + '0';
		n = n / 16;
		chek = n % 16;
		len--;
	}
	if (chek > 9 && chek < 16)
		str[0] = chek + ((s->chek_flag_x - ('x' - 'a')) - 10);
	return (str);
}

int					write_flag_x(t_print *s)
{
	unsigned int	i;

	s->chek_flag_x = *(s->format_str);
	i = va_arg(s->pi, int);
	CHECK((s->str = write_x(i, s)));
	if (s->shchek && !s->tchek)
		s->s = '0';
	if (s->tchek && !s->t && s->str[0] == '0')
		s->str[0] = '\0';
	s->strlen = ft_strlen(s->str);
	CHECKSTR((s->newf = ft_strtoch_int(s->str, s)));
	free(s->str);
	CHECKNEW((s->new = ft_strshir(s->newf, s)));
	write_str(s->new, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}
