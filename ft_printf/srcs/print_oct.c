/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/03 17:03:46 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 17:45:32 by aelharim         ###   ########.fr       */
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
	put_spaces(spaces, print);
	ft_putstr(tmp);
}

static char *azero_print(t_print *print, char *stock)
{
	char	*str;
	int		nb;
	int		i;

	i = 0;
	nb = nb_spaces(print, ft_strlen(stock) + 2);
	if (!(str = (char*)malloc(sizeof(char) * nb + 1)))
		exit (0);
	while (i < nb + 1)
	{
		str[i] = '0';
		i++;
	}
	return (str);
}

void		print_oct(va_list arg, t_print *print)
{
	char	*stock;
	int		spaces;

	stock = ft_itoa_base(va_arg(arg, int), 8);
	if (print->azero == 1)
		stock = ft_strjoin(azero_print(print, stock), stock);
	if (print->diez == 1 && *stock != 0)
		stock = ft_strjoin("0", stock);
	spaces = nb_spaces(print, ft_strlen(stock));
	print->ret += ft_strlen(stock);
	if (print->moins == 1)
		aff_gauche(print, stock, spaces);
	else
		aff_droite(print, stock, spaces);
	print->i += 1;
	re_init(print);
}
