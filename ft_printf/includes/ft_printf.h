/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:49:05 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 15:02:26 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_H
# define FT_PRINT_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_print
{
	int			ret;
	int			i;
	int			taille;
	int			plus;
	int			moins;
	int			prec;
	int			zero;
	int			spaces;
	int			signe;
	int			diez;
	int			espace;
	int			azero;
}				t_print;

int				ft_printf(const char *format, ...);
void			print_char(va_list arg, t_print *print);
void			print_int(va_list arg, t_print *print);
void			print_string(va_list arg, t_print *print);
void			print_long(va_list arg, t_print *print);
void			print_uint(va_list arg, t_print *print);
void			print_hexa(va_list arg, char c, t_print *print);
void			print_oct(va_list arg, t_print *print);
void			print_ptr(va_list arg, t_print *print);
void			spaces(va_list arg, t_print *print, const char *format);
void			check_arg(const char *format, va_list arg, t_print *print);
void			taille_mini(va_list arg, t_print *print, const char *format);
void			precision(va_list arg, t_print *print, const char *format);
void			put_zero(int zero, t_print *print);
void			check_attribut(const char *format, va_list arg, t_print *print);
void			re_init(t_print *print);
void			gerer_diez(t_print *print, const char *format, va_list arg);
void			gerer_zero(t_print *print, const char *format, va_list arg);
void			gerer_signe(t_print *print, const char *format, va_list arg);
int				nb_spaces(t_print *print, int taille);
int				nb_zero(t_print *print, int taille);
void			put_spaces(int spaces, t_print *print);
t_print			*init_print(void);

#endif
