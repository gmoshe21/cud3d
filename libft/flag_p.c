/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 16:03:18 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/10 04:06:33 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					len_x_p(long long n)
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

char				*write_x_p(long long n)
{
	char			*str;
	int				len;
	unsigned int	chek;

	len = len_x_p(n) + 1;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[0] = '0';
	str[1] = 'x';
	str[len--] = '\0';
	if (!n)
		str[2] = '0';
	chek = n % 16;
	while (n != 0)
	{
		if (chek > 9 && chek < 16)
			str[len--] = chek + (('x' - ('x' - 'a')) - 10);
		else if (chek < 10)
			str[len--] = chek + '0';
		n = n / 16;
		chek = n % 16;
	}
	if (chek > 9 && chek < 16)
		str[2] = chek + (('x' - ('x' - 'a')) - 10);
	return (str);
}

char				*ft_strshir_p(char *str, t_print *s)
{
	char			*new;
	int				len;
	int				x;

	x = 2;
	s->strlen = ft_strlen(str);
	if (!s->t)
		len = s->strlen - 1;
	if (s->strlen < s->t)
		len = s->t;
	else if (s->t)
		len = s->strlen;
	if (!(new = malloc(sizeof(char) * (len + x + 1))))
		return (0);
	len = 2;
	new[0] = '0';
	new[1] = 'x';
	if (s->strlen < s->t && s->t)
		while (x - 4 < s->t - s->strlen)
			new[x++] = '0';
	while (str[len] && !(s->tchek && !s->t))
		new[x++] = str[len++];
	new[x] = '\0';
	free(str);
	return (new);
}

int					write_flag_p(t_print *s)
{
	long long		i;

	i = va_arg(s->pi, long long);
	CHECK((s->str = write_x_p(i)));
	CHECKSTR((s->newf = ft_strshir_p(s->str, s)));
	CHECKNEW((s->new = ft_strshir(s->newf, s)));
	write_str(s->new, s);
	s->format_str++;
	s->first_s = 0;
	return (1);
}
