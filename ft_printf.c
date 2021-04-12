/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/01 19:54:19 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 21:49:41 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** %с	Символ типа char
** %s	Строка символов
** %р	Выводит на экран значение указателя
** %d	Десятичное число целого типа со знаком
** %i	Десятичное число целого типа со знаком
** %u	Десятичное число целого типа без знака
** %х	Шестнадцатиричное целое число без знака (буквы нижнего регистра)
** %Х	Шестнадцатиричное целое число без знака (буквы верхнего регистра)
** %%	Выводит символ %
** %[флаги][ширина][.точность]тип
*/

#include "ft_printf.h"

int			ft_printf(const char *line, ...)
{
	va_list		arg;
	t_struct	*par;
	int			count;
	char		*string;

	count = 0;
	string = (char*)line;
	if (!(par = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	par->count = 0;
	va_start(arg, line);
	while (string && *string != '\0')
	{
		if ((string = ft_strchr_print_c(string, '%', par)))
		{
			if (search_argument(&string, par, &arg) == -1)
				break ;
		}
		else
			break ;
	}
	count = par->count;
	free(par);
	va_end(arg);
	return (count);
}
