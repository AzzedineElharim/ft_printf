/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 16:48:43 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 16:29:47 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	aff_gauche(t_print *print, char *tmp, int spaces)
{
	ft_putstr(tmp);
	put_spaces(spaces, print);
}

static void	aff_droite(t_print *print, char *tmp, int spaces)
{
	if (print->azero == 1)
	{
		put_zero(spaces, print);
		ft_putstr(tmp);
	}
	else
	{
		put_spaces(spaces, print);
		ft_putstr(tmp);
	}
}

static char	*azero_print(t_print *print, char *stock)
{
	char	*str;
	char	*tmp;
	int		nb;
	int		i;

	i = 0;
	if (!(str = ft_strdup("0X")))
		exit (0);
	nb = nb_spaces(print, ft_strlen(stock) + 2);
	if (!(tmp =(char*)malloc(sizeof(char) * nb)))
		exit (0);
	while (i < nb)
	{
		tmp[i] = '0';
		i++;
	}
	if (!(str = ft_strjoin(str, tmp)))
		exit (0);
	print->azero = 0;
	return (str);
}

void		print_hexa(va_list arg, char c, t_print *print)
{
	char	*stock;
	char	*tmp;
	int		spaces;

	stock = ft_itoa_base(va_arg(arg, int), 16);
	if (print->diez == 1 && print->azero == 1)
		stock = ft_strjoin(azero_print(print, stock), stock);
	else if (print->diez == 1 && print->azero == 0)
		stock = ft_strjoin("0X", stock);
	tmp = stock;
	spaces = nb_spaces(print, ft_strlen(stock));
	if (c == 'x')
	{
		while (*stock != '\0')
		{
			*stock = ft_tolower(*stock);
			stock++;
		}
	}
	if (print->moins == 1)
		aff_gauche(print, tmp, spaces);
	else
		aff_droite(print, tmp, spaces);
	print->ret += ft_strlen(tmp);
	print->i += 1;
	re_init(print);
}
