/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:20:13 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 15:01:50 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_print		*init_print(void)
{
	t_print *print;

	print = ft_memalloc(sizeof(t_print));
	print->ret = 0;
	print->i = 0;
	print->prec = 0;
	print->plus = 0;
	print->moins = 0;
	print->zero = 0;
	print->spaces = 0;
	print->taille = 0;
	print->signe = 0;
	print->diez = 0;
	print->espace = 0;
	print->azero = 0;
	return (print);
}

void		re_init(t_print *print)
{
	print->taille = 0;
	print->signe = 0;
	print->plus = 0;
	print->moins = 0;
	print->spaces = 0;
	print->zero = 0;
	print->prec = 0;
	print->diez = 0;
	print->espace = 0;
	print->azero = 0;
}
