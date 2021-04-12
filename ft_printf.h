/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heusebio <heusebio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 13:44:48 by heusebio          #+#    #+#             */
/*   Updated: 2020/07/23 21:19:24 by heusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_struct
{
	char	minus;
	char	zero;
	int		width;
	int		ac;
	char	type;
	int		count;
}				t_struct;

int				ft_printf(const char *line, ...);
void			ft_putnbr(int n, t_struct *par);
char			*ft_strchr_print_c(const char *s, int c, t_struct *par);
int				ft_strlen(char *str);
int				ft_isdigit(int c);
int				ft_print_x(t_struct *par, va_list *arg);
int				ft_print_uint(t_struct *par, va_list *arg);
int				ft_print_s(t_struct *par, va_list *arg);
int				ft_print_p(t_struct *par, va_list *arg);
int				ft_print_d_i(t_struct *par, va_list *arg);
int				ft_print_c(t_struct *par, char symbol);
int				search_argument(char **string, t_struct *par, va_list *arg);
void			ft_putunbr(unsigned int digit, t_struct *par);
int				len_u_digit(size_t digit, char type);
int				len_digit(int digit);
void			ft_putchar_len(char c, int len, t_struct *par);
int				ft_putchar(char c);
int				print_max_digit(t_struct *par, int digit);

#endif
