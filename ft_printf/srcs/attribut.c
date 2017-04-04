/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attribut.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:33:50 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 15:02:29 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	spaces(va_list arg, t_print *print, const char *format)
{
	print->i += 1;
	while ( format[print->i + 1] == ' ')
		print->i += 1;
	print->espace = 1;
	check_attribut(format, arg, print);
}

void	taille_mini(va_list arg, t_print *print, const char *format)
{
	int	size;
	char	*str;

	size = 0;
	print->i += 1;
	while (format[print->i] >= '0' && format[print->i] <= '9')
	{
		size++;
		print->i += 1;
	}
	str = ft_strsub(format, print->i - size , size);
	print->taille = ft_atoi(str);
	print->i -= 1;
	check_attribut(format, arg, print);
}

void	precision(va_list arg, t_print *print, const char *format)
{
	int	size;
	char	*str;

	size = 0;
	print->i += 2;
	if (format[print->i] == 's')
		return ;
	while (format[print->i] >= '0' && format[print->i] <= '9')
	{
		size++;
		print->i += 1;
	}
	str = ft_strsub(format, print->i - size, size);
	print->prec = ft_atoi(str);
	print->i -= 1;
	check_arg(format, arg, print);
}

void	gerer_diez(t_print *print, const char *format, va_list arg)
{
	print->i += 1;
	while (format[print->i] == '#')
		print->i += 1;
	print->diez = 1;
	print->i -= 1;
	check_attribut(format, arg, print);
}

void	gerer_zero(t_print *print, const char *format, va_list arg)
{
	print->i += 1;
	while (format[print->i] == '0')
		print->i += 1;
	print->azero = 1;
	print->i -= 1;
	check_attribut(format, arg, print);
}
