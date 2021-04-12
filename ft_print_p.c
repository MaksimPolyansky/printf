/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:06:12 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 19:08:00 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_point(size_t pointer, t_struct *par)
{
	size_t	num;

	if (pointer > 15)
		ft_print_point(pointer / 16, par);
	num = pointer % 16 + 48;
	if (ft_isdigit(num))
		par->count += ft_putchar(num);
	else
		par->count += ft_putchar(num + 39);
}

static int	print_neg(t_struct *par, size_t pointer)
{
	par->count += ft_putchar('0');
	par->count += ft_putchar('x');
	ft_print_point(pointer, par);
	ft_putchar_len(' ', par->width - len_u_digit(pointer, 'p') - 2, par);
	return (1);
}

static int	print_poz(t_struct *par, size_t pointer)
{
	if (par->zero != 0)
	{
		par->count += ft_putchar('0');
		par->count += ft_putchar('x');
		ft_putchar_len('0', par->width - len_u_digit(pointer, 'p') - 2, par);
		ft_print_point(pointer, par);
		return (1);
	}
	ft_putchar_len(' ', par->width - len_u_digit(pointer, 'p') - 2, par);
	par->count += ft_putchar('0');
	par->count += ft_putchar('x');
	ft_print_point(pointer, par);
	return (1);
}

int			ft_print_p(t_struct *par, va_list *arg)
{
	size_t	pointer;

	pointer = va_arg(*arg, size_t);
	if (par->minus != 0)
		return (print_neg(par, pointer));
	return (print_poz(par, pointer));
}
