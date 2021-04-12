/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:06:59 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/22 23:27:49 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_neg(t_struct *par, unsigned int digit)
{
	int accuracy;

	ft_putchar_len('0', par->ac - len_u_digit(digit, 'u'), par);
	ft_putunbr(digit, par);
	accuracy = (par->ac > len_u_digit(digit, 'u')) ? (par->ac - \
											len_u_digit(digit, 'u')) : 0;
	ft_putchar_len(' ', par->width - accuracy - len_u_digit(digit, 'u'), par);
	return (1);
}

static int	print_poz(t_struct *par, unsigned int digit)
{
	int		accuracy;
	char	c;

	if (par->ac != -1)
	{
		accuracy = (par->ac > len_u_digit(digit, 'u')) ? (par->ac - \
											len_u_digit(digit, 'u')) : 0;
		ft_putchar_len(' ', par->width - accuracy - \
											len_u_digit(digit, 'u'), par);
		ft_putchar_len('0', accuracy, par);
		ft_putunbr(digit, par);
		return (1);
	}
	c = (par->zero != 0) ? '0' : ' ';
	ft_putchar_len(c, par->width - len_u_digit(digit, 'u'), par);
	ft_putunbr(digit, par);
	return (1);
}

int			ft_print_uint(t_struct *par, va_list *arg)
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
