/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 15:17:22 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 14:48:31 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			nb_zero(t_print *print, int taille)
{
	int		nb_zero;

	nb_zero = 0;
	if ((nb_zero = print->prec - taille) <= 0)
		return (0);
	else
		return (print->zero = nb_zero);
}

int			nb_spaces(t_print *print, int taille)
{
	int		nb_spaces;

	nb_spaces = 0;
	if ((nb_spaces = print->taille - print->zero - taille - print->signe) <= 0)
	{
		if (print->espace == 1)
			return (print->spaces = 1);
		else
			return (0);
	}
	else
		return (print->spaces = nb_spaces);
}
void		put_spaces(int spaces, t_print *print)
{
	while (spaces > 0)
	{
		ft_putchar(' ');
		spaces--;
		print->ret += 1;
	}
}
void		put_zero(int zero, t_print *print)
{
	while (zero > 0)
	{
		ft_putchar('0');
		zero--;
		print->ret += 1;
	}
}

void		gerer_signe(t_print *print, const char *format, va_list arg)
{
	print->i += 1;
	if (format[print->i] == '+')
		print->plus = 1;
	else if (format[print->i] == '-')
		print->moins = 1;
	check_attribut(format, arg, print);
}
