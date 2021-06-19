/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 17:57:46 by mwen              #+#    #+#             */
/*   Updated: 2021/06/19 15:34:09 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>//delete

typedef struct s_flags
{
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	asterisk;
}		t_flags;

int		ft_printf(const char *input, ...);
int		ft_is_flag(int c);
int		ft_is_type(int c);

t_flags	ft_flag_minus(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_dot(const char *cp, int start, t_flags *flags, va_list args);

int		ft_treat_types(t_flags flags, va_list args);
int		ft_treat_char(char c, t_flags flags);
int		ft_treat_string(char *str, t_flags flags);
int		ft_treat_pointer(unsigned long long ull, t_flags flags);
char	*ft_str_tolower(char *str);
char	*ft_decimal_to_hexa(unsigned long long ull, int base);
int		ft_treat_int(long long nb, t_flags flags);
int		ft_treat_uint(unsigned int uint, t_flags flags);
int		ft_treat_charuint(char *uint_in_char, t_flags flags);
int		ft_putcharuint(char *uint_in_char, t_flags flags);
int		ft_treat_hexa(unsigned int uint, int lower, t_flags flags);
int		ft_treat_percent(t_flags flags);

int		ft_treat_width(int width, int len, int has_zero);
int		ft_putstrprec(char *str, int prec);
int		ft_putchar(int c);

#endif