/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoshe <gmoshe@student.42.tr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 16:52:29 by gmoshe            #+#    #+#             */
/*   Updated: 2020/07/10 04:07:10 by gmoshe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_print
{
	va_list		pi;
	int			len;
	int			strlen;
	char		*format_str;
	int			chek_flag_x;
	char		chek_spets;
	int			left;
	int			sh;
	int			first_s;
	char		x;
	int			t;
	int			int_len;
	int			int_x;
	int			x_zn;
	int			tchek;
	int			shchek;
	int			s;
	char		*str;
	char		*newf;
	char		*new;
	int			i;
	char		st;
	int			sint;
}				t_print;

int				ft_printf(const char *format, ...);
int				write_flag_c(t_print *s);
int				write_flag_s(t_print *s);
int				write_flag_integ(t_print *s);
int				write_flag_u(t_print *s);
char			*ft_itoa(int n);
char			*ft_itoa_u(unsigned int n);
int				write_flag_x(t_print *s);
void			checker(t_print *s);
char			*ft_strshir(char *str, t_print *s);
size_t			ft_strlen(const char *str);
void			toch(t_print *s);
char			*ft_strtoch(char *str, t_print *s);
char			*ft_strtoch_int(char *str, t_print *s);
void			write_str(char *str, t_print *s);
int				write_flag_p(t_print *s);
void			*ft_calloc(size_t number, size_t size);
void			*ft_memset(void *str, int c, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t siz);
int				write_flag_for(t_print *s);
char			*ft_strdup(const char *str);
void			shtoch(t_print *s);
void			miss(t_print *s);
int				str_null(t_print *s);
char			*ft_strshir_c(char *str, t_print *s);
void			free_str(t_print *s);
void			*ft_memchr(const void *arr, int c, size_t n);
void			intnull(t_print *s);

# define CHECK(x) if(!x) return (0)
# define CHECKSTR(x) if(!x) return (-1)
# define CHECKNEW(x) if(!x) return (-2)
# define ERROR(x) if(x == -1) return (-1)
#endif
