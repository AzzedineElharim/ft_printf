/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 17:59:49 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/03 17:08:48 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		print_ptr(va_list arg, t_print *print)
{
	long		adr;
	char		*stock;

	adr = va_arg(arg, unsigned int);
	stock = ft_itoa_base(adr, 16);
	printf("yo \n");
	ft_putstr(stock);
	print->ret += ft_strlen(stock);
}
