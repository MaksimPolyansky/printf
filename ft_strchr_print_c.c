/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_print_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:43:06 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/22 23:14:19 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

char	*ft_strchr_print_c(const char *s, int c, t_struct *parametrs)
{
	if ((char)c == '\0')
	{
		while (*s != '\0')
		{
			ft_putchar_fd(*s, 1);
			s++;
			parametrs->count++;
		}
		return ((char *)s);
	}
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		ft_putchar_fd(*s, 1);
		s++;
		parametrs->count++;
	}
	return (NULL);
}
