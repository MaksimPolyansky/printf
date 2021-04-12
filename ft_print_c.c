/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:05:22 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 19:05:09 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_percent(t_struct *par, char symbol)
{
	char	c;

	if (par->minus != 0)
	{
		par->count += write(1, &symbol, 1);
		ft_putchar_len(' ', par->width - 1, par);
		return (1);
	}
	else
	{
		c = (par->zero == 0) ? ' ' : '0';
		ft_putchar_len(c, par->width - 1, par);
		par->count += write(1, &symbol, 1);
		return (1);
	}
}

int			ft_print_c(t_struct *par, char symbol)
{
	if (symbol == '%')
		return (print_percent(par, symbol));
	else
	{
		if (par->minus != 0)
			par->count += write(1, &symbol, 1);
		ft_putchar_len(' ', par->width - 1, par);
		if (par->minus == 0)
			par->count += write(1, &symbol, 1);
		return (1);
	}
}
