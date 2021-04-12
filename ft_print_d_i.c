/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:06:39 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 20:01:41 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_digit(t_struct *par, int digit)
{
	int	accuracy;

	if (digit < 0)
	{
		accuracy = (par->ac > (len_digit(digit) - 1)) ? (par->ac - \
												len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', par->width - accuracy - len_digit(digit), par);
		par->count += ft_putchar('-');
		ft_putchar_len('0', accuracy, par);
		ft_putnbr(digit * -1, par);
	}
	else
	{
		accuracy = (par->ac > len_digit(digit)) ? (par->ac - \
													len_digit(digit)) : 0;
		ft_putchar_len(' ', par->width - accuracy - len_digit(digit), par);
		ft_putchar_len('0', accuracy, par);
		ft_putnbr(digit, par);
	}
	return (1);
}

static int	print_poz(t_struct *par, int digit)
{
	char	c;

	if (par->ac == -1)
	{
		if (digit < 0)
		{
			if (par->zero != 0)
			{
				par->count += ft_putchar('-');
				ft_putchar_len('0', par->width - len_digit(digit), par);
				ft_putnbr(digit * -1, par);
				return (1);
			}
			ft_putchar_len(' ', par->width - len_digit(digit), par);
			ft_putnbr(digit, par);
		}
		else
		{
			c = (par->zero != 0) ? '0' : ' ';
			ft_putchar_len(c, par->width - len_digit(digit), par);
			ft_putnbr(digit, par);
		}
		return (1);
	}
	return (print_digit(par, digit));
}

static int	print_neg(t_struct *par, int digit)
{
	int	accuracy;

	if (digit >= 0)
	{
		ft_putchar_len('0', par->ac - len_digit(digit), par);
		ft_putnbr(digit, par);
		accuracy = (par->ac > len_digit(digit)) ? \
							(par->ac - len_digit(digit)) : 0;
		ft_putchar_len(' ', par->width - accuracy - len_digit(digit), par);
	}
	else
	{
		par->count += ft_putchar('-');
		ft_putchar_len('0', par->ac - len_digit(digit) + 1, par);
		ft_putnbr(digit * -1, par);
		accuracy = (par->ac > (len_digit(digit) - 1)) ? (par->ac - \
												len_digit(digit) + 1) : 0;
		ft_putchar_len(' ', par->width - accuracy - len_digit(digit), par);
	}
	return (1);
}

int			ft_print_d_i(t_struct *par, va_list *arg)
{
	int	digit;

	digit = va_arg(*arg, int);
	if (digit == 0 && par->ac == 0)
	{
		ft_putchar_len(' ', par->width, par);
		return (1);
	}
	if (digit == -2147483648)
		return (print_max_digit(par, digit));
	if (par->minus != 0)
		return (print_neg(par, digit));
	return (print_poz(par, digit));
}
