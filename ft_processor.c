/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:33:12 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 18:33:02 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*search_flags(char *string, t_struct *par)
{
	par->minus = 0;
	par->zero = 0;
	while (string)
	{
		if (*string == '-')
			par->minus = '-';
		else if (*string == '0')
			par->zero = '0';
		else
			return (string);
		string++;
	}
	return (NULL);
}

static char	*search_width(char *string, va_list *arg, t_struct *par)
{
	int	width;

	width = 0;
	par->width = 0;
	if (*string == '*')
	{
		if ((par->width = va_arg(*arg, int)) < 0)
		{
			par->width *= -1;
			par->minus = '-';
		}
		return (++string);
	}
	if (*string == '.' || !ft_isdigit(*string))
	{
		par->width = 0;
		return (string);
	}
	while (ft_isdigit(*string))
	{
		width = width * 10 + *string - 48;
		string++;
	}
	par->width = width;
	return (string);
}

static char	*search_accuracy(char *string, t_struct *par, va_list *arg)
{
	int	accuracy;

	accuracy = 0;
	par->ac = -1;
	if (*string == '*')
	{
		if ((par->ac = va_arg(*arg, int)) < 0)
			par->ac = -1;
		return (++string);
	}
	if (ft_isdigit(*string))
	{
		while (ft_isdigit(*string))
		{
			accuracy = accuracy * 10 + *string - 48;
			string++;
		}
		par->ac = accuracy;
	}
	else
		par->ac = 0;
	return (string);
}

static int	search_type(t_struct *par, va_list *arg)
{
	if (par->type == 'c')
		return (ft_print_c(par, (char)va_arg(*arg, int)));
	else if (par->type == 's')
		return (ft_print_s(par, arg));
	else if (par->type == 'p')
		return (ft_print_p(par, arg));
	else if (par->type == 'd' || par->type == 'i')
		return (ft_print_d_i(par, arg));
	else if (par->type == 'u')
		return (ft_print_uint(par, arg));
	else if (par->type == 'x' || par->type == 'X')
		return (ft_print_x(par, arg));
	else if (par->type == '%')
		return (ft_print_c(par, '%'));
	return (-1);
}

int			search_argument(char **string, t_struct *par, va_list *arg)
{
	*string = search_flags((*string) + 1, par);
	*string = search_width(*string, arg, par);
	if (**string == '.')
		*string = search_accuracy((*string) + 1, par, arg);
	else
		par->ac = -1;
	par->type = **string;
	(*string)++;
	return (search_type(par, arg));
}
