/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 14:42:54 by aelharim          #+#    #+#             */
/*   Updated: 2017/03/30 19:48:13 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void				print_int(va_list arg, t_print *print)
{
	int			stock;

	stock = va_arg(arg, int);
	print->ret += ft_strlen(ft_itoa(stock));
	if (print->moins == 1)
	{
		if (print->plus == 1 && stock > 0)
		{
			print->ret += 1;
			ft_putchar('+');
			put_zero(print, ft_strlen(ft_itoa(stock)));
			ft_putnbr(stock);
			put_spaces(print, ft_strlen(ft_itoa(stock)) + 1);
			print->i += 1;
		}
		else if (stock < 0)
		{
			print->ret += 1;
			ft_putchar('-');
			print->zero += 1;
			put_zero(print, ft_strlen(ft_itoa(stock)));
			print->zero -= 1;
			ft_putnbr(stock * -1);
			print->prec -= 1;
			put_spaces(print, ft_strlen(ft_itoa(stock)) + 1);
			print->i += 1;
		}
		else
		{
			put_zero(print, ft_strlen(ft_itoa(stock)));
			ft_putnbr(stock);
			put_spaces(print, ft_strlen(ft_itoa(stock)) + 1);
			print->i += 1;
		}
		return ;
	}
	else if ((print->plus == 1 && stock > 0) && print->moins ==  0 && print->zero != 0)
	{
		print->zero += 1;
		print->ret += 1;
		put_spaces(print, ft_strlen(ft_itoa(stock)) + 1);
		ft_putchar('+');
		print->zero -= 1;
		put_zero(print, ft_strlen(ft_itoa(stock)));
		ft_putnbr(stock);
		print->i += 1;
		return ;
	}
	else
	{
		put_spaces(print, ft_strlen(ft_itoa(stock)));
		put_zero(print, ft_strlen(ft_itoa(stock)));
		ft_putnbr(stock);
		print->i += 1;
	}
}

void				print_char(va_list arg, t_print *print)
{
	char			stock;

	stock = (char)va_arg(arg, int);;
	put_spaces(print, 1);
	ft_putchar(stock);
	print->ret += 1;
	print->i += 1;
}

void				print_string(va_list arg, t_print *print)
{
	char			*stock;

	stock = va_arg(arg, char*);
	put_spaces(print, ft_strlen(stock));
	ft_putstr(stock);
	print->ret += ft_strlen(stock);
	print->i += 1;
}

void			print_long(va_list arg, t_print *print)
{
	long		stock;

	stock = va_arg(arg, long);
	put_spaces(print, ft_strlen(ft_itoa(stock)));
	ft_putnbr_long(stock);
	print->ret += ft_strlen(ft_itoa(stock));
	print->i += 1;
}

void				print_uint(va_list arg, t_print *print)
{
	unsigned int	stock;

	stock = va_arg(arg, unsigned int);
	put_spaces(print, ft_strlen(ft_itoa(stock)));
	ft_putnbr_uint(stock);
	print->ret += ft_strlen(ft_itoa(stock));
	print->i += 1;
}
