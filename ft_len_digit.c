/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 21:37:49 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 21:19:06 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len_u_digit(size_t digit, char type)
{
	int	count;
	int	point;

	count = 1;
	point = (type == 'x' || type == 'X' || type == 'p') ? 16 : 10;
	while (digit / point)
	{
		digit /= point;
		count++;
	}
	return (count);
}

int	len_digit(int digit)
{
	int				count;
	unsigned int	num;

	count = 1;
	if (digit < 0)
	{
		count++;
		num = digit * -1;
	}
	else
		num = digit;
	while (num / 10)
	{
		count++;
		num /= 10;
	}
	return (count);
}
