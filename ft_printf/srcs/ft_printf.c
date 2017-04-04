/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:37:52 by aelharim          #+#    #+#             */
/*   Updated: 2017/04/04 18:01:05 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

void				check_arg(const char *format, va_list arg, t_print *print)
{
	if (format[print->i +1] == 'd' || format[print->i + 1] == 'i')
		print_int(arg, print);
	else if (format[print->i + 1] == 'c')
		print_char(arg, print);
	else if (format[print->i + 1] == 's')
		print_string(arg, print);
	else if (format[print->i + 1] == 'D')
		print_long(arg, print);
	else if (format[print->i + 1] == 'u' || format[print->i + 1] == 'U')
		print_uint(arg, print);
	else if (format[print->i + 1] == 'x' || format[print->i + 1] == 'X')
		print_hexa(arg, format[print->i + 1], print);
	else if (format[print->i + 1] == 'o')
		print_oct(arg, print);
	else if(format[print->i + 1] == 'p')
		print_ptr(arg, print);
	else if (format[print->i + 1] == '%')
	{
		print->ret++;
		ft_putchar('%');
	}
}

void			check_attribut(const char *format, va_list arg, t_print *print)
{
	if (format[print->i + 1] == ' ')
		spaces(arg, print, format);
	else if (format[print->i + 1] > '0' && format[print->i + 1] <= '9')
		taille_mini(arg, print, format);
	else if (format[print->i + 1] == '.')
		precision(arg, print, format);
	else if ((format[print->i + 1] == '+' || format[print->i + 1] == '-'))
		gerer_signe(print, format, arg);
	else if (format[print->i + 1] == '#')
		gerer_diez(print, format, arg);
	else if (format[print->i + 1] == '0')
		gerer_zero(print, format, arg);
}

int				reader(va_list arg, const char *format)
{
	t_print		*print;

	print = init_print();
	while (format[print->i] != '\0')
	{
		if (format[print->i] == '%')
		{
			check_attribut(format, arg, print);
			check_arg(format, arg, print);
			print->i += 1;
		}
		if (format[print->i] != '\0')
		{
			ft_putchar(format[print->i]);
			print->ret++;
			print->i++;
		}
	}
	return (print->ret);
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	int			ret;
	
	va_start(arg, format);
	ret = reader(arg, format);
	va_end(arg);
	return (ret);
}

int				main()
{
//	int		a = 25;
//	char	*str = "je suis str";
//	int		c = 12365784;

//	printf("4567 |%-10]5d| plip\n", 12);
/*	printf("4567 |%105d| plip\n", 12);
	printf("|%.5d|\n", -12);
	printf("|%10d|\n", -12);
	printf("|%010d|\n", -12);
	printf("|%-10.5d|\n", -12);*/
//	printf("|%-010.5d|\n", -12);
	printf("%d\n", printf("bonjour lolilol a = |%-#20o| b = |%5c| c = |%020ld|", 60589000, 'z', 4200000456));
	printf("%d\n", ft_printf("bonjour lolilol a = |%-#20o| b = |%5c| c = |%020D|", 60589000, 'z', 4200000456));
	return (0);
}








