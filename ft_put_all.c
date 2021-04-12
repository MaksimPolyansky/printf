/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 10:32:20 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 15:13:34 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_len(char c, int len, t_struct *par)
{
	while (len > 0)
	{
		write(1, &c, 1);
		len--;
		par->count++;
	}
}

void	ft_putunbr(unsigned int digit, t_struct *par)
{
	if (digit >= 10)
		ft_putunbr(digit / 10, par);
	par->count += ft_putchar(digit % 10 + '0');
}

void	ft_putnbr(int n, t_struct *par)
{
	unsigned int	nbr;

	if (n < 0)
	{
		par->count += ft_putchar('-');
		nbr = -1 * n;
	}
	else
		nbr = n;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, par);
	par->count += ft_putchar(nbr % 10 + '0');
}

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
