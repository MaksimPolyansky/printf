/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_max_digit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 19:50:08 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 22:56:47 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_max_digit_help(t_struct *par, int digit)
{
	if (par->zero != 0)
	{
		par->count += ft_putchar('-');
		ft_putchar_len('0', par->width - len_digit(digit), par);
		par->count += ft_putchar('2');
		ft_putnbr(147483648, par);
		return (1);
	}
	ft_putchar_len(' ', par->width - len_digit(digit), par);
	par->count += ft_putchar('-');
	par->count += ft_putchar('2');
	ft_putnbr(147483648, par);
	return (1);
}

int			print_max_digit(t_struct *par, int digit)
{
	int	ac;

	if (par->minus != 0)
	{
		par->count += ft_putchar('-');
		ft_putchar_len('0', par->ac - len_digit(digit) + 1, par);
		par->count += ft_putchar('2');
		ft_putnbr(147483648, par);
		par->ac = (par->ac > (len_digit(digit) - 1)) ? (par->ac - \
													len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', par->width - par->ac - len_digit(digit), par);
		return (1);
	}
	if (par->ac != -1)
	{
		ac = (par->ac > (len_digit(digit) - 1)) ? (par->ac - \
													len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', par->width - ac - len_digit(digit), par);
		par->count += ft_putchar('-');
		ft_putchar_len('0', par->ac - len_digit(digit) + 1, par);
		par->count += ft_putchar('2');
		ft_putnbr(147483648, par);
		return (1);
	}
	return (print_max_digit_help(par, digit));
}
