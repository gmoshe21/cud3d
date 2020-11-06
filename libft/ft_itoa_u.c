/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 12:51:25 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/21 14:17:19 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			len_str(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa_u(unsigned int n)
{
	char	*str;
	int		len;

	len = len_str(n);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	str[0] = '0';
	str[len--] = '\0';
	if (n == 0)
		return (str);
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
