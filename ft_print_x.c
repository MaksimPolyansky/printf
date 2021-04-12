/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:07:33 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 18:57:53 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex(unsigned int digit, t_struct *par)
{
	int	num;
	int	symbol;

	symbol = (par->type == 'x') ? 39 : 7;
	if (digit > 15)
		ft_print_hex(digit / 16, par);
	num = digit % 16 + 48;
	if (ft_isdigit(num))
		par->count += ft_putchar(num);
	else
		par->count += ft_putchar(num + symbol);
}

static int	print_neg(t_struct *par, unsigned int digit)
{
	int	accuracy;

	ft_putchar_len('0', par->ac - len_u_digit(digit, 'x'), par);
	ft_print_hex(digit, par);
	accuracy = (par->ac > len_u_digit(digit, 'x')) ? (par->ac - \
											len_u_digit(digit, 'x')) : 0;
	ft_putchar_len(' ', par->width - accuracy - len_u_digit(digit, 'x'), par);
	return (1);
}

static int	print_poz(t_struct *par, unsigned int digit)
{
	int		accuracy;
	char	c;

	if (par->ac != -1)
	{
		accuracy = (par->ac > len_u_digit(digit, 'x')) ? (par->ac - \
											len_u_digit(digit, 'x')) : 0;
		ft_putchar_len(' ', par->width - accuracy - \
										len_u_digit(digit, 'x'), par);
		ft_putchar_len('0', accuracy, par);
		ft_print_hex(digit, par);
		return (1);
	}
	c = (par->zero != 0) ? '0' : ' ';
	ft_putchar_len(c, par->width - len_u_digit(digit, 'x'), par);
	ft_print_hex(digit, par);
	return (1);
}

int			ft_print_x(t_struct *par, va_list *arg)
{
	unsigned int	digit;

	digit = va_arg(*arg, unsigned int);
	if (digit == 0 && par->ac == 0)
	{
		ft_putchar_len(' ', par->width, par);
		return (1);
	}
	if (par->minus != 0)
		return (print_neg(par, digit));
	return (print_poz(par, digit));
}
