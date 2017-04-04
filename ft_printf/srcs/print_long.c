/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:19:28 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 18:03:39 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void			det_signe(long stock, t_print *print)
{
	if (print->plus == 1 && stock > 0)
		print->signe = 1;
	else if (stock < 0)
		print->signe = 1;
}

static void			aff_gauche(t_print *print, long stock, int zero, int spaces)
{
	if (stock > 0)
	{
		if (print->plus == 1)
		{
			ft_putchar('+');
			print->ret += 1;
		}
		put_zero(zero, print);
		ft_putnbr_long(stock);
		put_spaces(spaces, print);
	}
	else
	{
		ft_putchar('-');
		put_zero(zero, print);
		ft_putnbr_long(stock * -1);
		put_spaces(spaces, print);
	}
}

static void			azero_droite(t_print *print, long stock, int zero, int spaces)
{
	if (stock > 0)
	{
		if (print->plus == 1)
		{
			ft_putchar('+');
			print->ret += 1;
		}
		put_zero(spaces, print);
		put_zero(zero, print);
		ft_putnbr_long(stock);
	}
	else
	{
		ft_putchar('-');
		put_zero(spaces, print);
		put_zero(zero, print);
		ft_putnbr_long(stock * -1);
	}
}

static void			aff_droite(t_print *print, long stock, int zero , int spaces)
{
	if (print->azero == 1)
		azero_droite(print, stock, zero, spaces);
	else
	{if (stock > 0)
		{
			put_spaces(spaces, print);
			if (print->plus == 1)
			{
				ft_putchar('+');
				print->ret += 1;
			}
			put_zero(zero, print);
			ft_putnbr_long(stock);
		}
		else
		{
			put_spaces(spaces, print);
			ft_putchar('-');
			put_zero(zero, print);
			ft_putnbr_long(stock * -1);
		}
	}
}

void				print_long(va_list arg, t_print *print)
{
	long			stock;
	int				zero;
	int				spaces;

	stock = va_arg(arg, long);
	det_signe(stock, print);
	if (stock < 0)
	{
		zero = nb_zero(print, ft_strlen(ft_itoa(stock * -1)));
		spaces = nb_spaces(print,ft_strlen(ft_itoa(stock * -1)));
	}
	else
	{
		zero = nb_zero(print, ft_strlen(ft_itoa(stock)));
		spaces = nb_spaces(print,ft_strlen(ft_itoa(stock)));
	}
	print->ret += ft_strlen(ft_itoa(stock));
	if (print->moins == 1)
		aff_gauche(print, stock, zero, spaces);
	else
		aff_droite(print, stock, zero, spaces);
	print->i += 1;
	re_init(print);
}
