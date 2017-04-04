/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:11:25 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/03 16:25:06 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	aff_gauche(t_print *print, char *stock, int spaces)
{
	ft_putstr(stock);
	put_spaces(spaces, print);
}

static void	aff_droite(t_print *print, char *stock, int spaces)
{
	put_spaces(spaces, print);
	ft_putstr(stock);
}

void		print_string(va_list arg, t_print *print)
{
	char	*stock;
	int		spaces;

	stock = va_arg(arg, char*);
	spaces = nb_spaces(print, ft_strlen(stock));
	print->ret += ft_strlen(stock);
	if (print->moins == 1)
		aff_gauche(print, stock, spaces);
	else
		aff_droite(print, stock, spaces);
	print->i += 1;
	re_init(print);
}
