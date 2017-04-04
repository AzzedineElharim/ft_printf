/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 15:55:15 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/03 16:10:55 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	aff_gauche(t_print *print, char stock , int spaces)
{
	ft_putchar(stock);
	put_spaces(spaces, print);
}

static void	aff_droite(t_print *print, char stock, int spaces)
{
	put_spaces(spaces, print);
	ft_putchar(stock);
}
void		print_char(va_list arg, t_print *print)
{
	char	stock;
	int		spaces;

	stock = (char)va_arg(arg, int);
	spaces = nb_spaces(print, 1);
	print->ret += 1;
	if (print->moins == 1)
		aff_gauche(print, stock, spaces);
	else
		aff_droite(print, stock, spaces);
	print->i += 1;
	re_init(print);
}
