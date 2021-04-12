/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:05:54 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 15:10:01 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_poz(t_struct *par, char *string)
{
	int	count;
	int	len;

	count = 0;
	if (par->ac != -1)
	{
		if (par->ac == 0)
		{
			ft_putchar_len(' ', par->width, par);
			return (1);
		}
		len = (par->ac > ft_strlen(string)) ? ft_strlen(string) : par->ac;
		ft_putchar_len(' ', par->width - len, par);
		while (count < len)
			par->count += ft_putchar(string[count++]);
		return (1);
	}
	ft_putchar_len(' ', par->width - ft_strlen(string), par);
	while (count < ft_strlen(string))
		par->count += ft_putchar(string[count++]);
	return (1);
}

static int	print_neg(t_struct *par, char *string)
{
	int	count;

	count = 0;
	if (par->ac != -1)
	{
		while (string[count] != '\0' && count < par->ac)
			par->count += ft_putchar(string[count++]);
		while (count++ < par->width)
			par->count += ft_putchar(' ');
		return (1);
	}
	while (count < ft_strlen(string))
		par->count += ft_putchar(string[count++]);
	ft_putchar_len(' ', par->width - ft_strlen(string), par);
	return (1);
}

int			ft_print_s(t_struct *par, va_list *arg)
{
	char	*string;

	if (!(string = va_arg(*arg, char *)))
		string = "(null)";
	if (par->minus != 0)
		return (print_neg(par, string));
	return (print_poz(par, string));
}
