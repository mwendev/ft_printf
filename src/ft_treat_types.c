/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_types.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:52:43 by mwen              #+#    #+#             */
/*   Updated: 2021/06/21 22:04:42 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_is_type(int c)
{
	return ((c == 'c') | (c == 's') | (c == 'p') | (c == 'd') | (c == 'i')
		| (c == 'u') | (c == 'x') | (c == 'X') | (c == '%'));
}

int	ft_is_flag(int c)
{
	return ((c == '-') | (c == ' ') | (c == '0') | (c == '.') | (c == '*'));
}

int	ft_treat_types(t_flags flags, va_list args)
{
	int	ret;

	ret = 0;
	if (flags.type == 'c')
		ret = ft_treat_char(va_arg(args, int), flags);
	else if (flags.type == 's')
		ret = ft_treat_string(va_arg(args, char *), flags);
	else if (flags.type == 'p')
		ret = ft_treat_pointer(va_arg(args, unsigned long long), flags);
	else if (flags.type == 'd' || flags.type == 'i')
		ret = ft_treat_int(va_arg(args, int), flags);
	else if (flags.type == 'u')
		ret += ft_treat_uint(va_arg(args, unsigned int), flags);
	else if (flags.type == 'x')
		ret += ft_treat_hexa(va_arg(args, unsigned int), 1, flags);
	else if (flags.type == 'X')
		ret += ft_treat_hexa(va_arg(args, unsigned int), 0, flags);
	else if (flags.type == '%')
		ret += ft_treat_percent(flags);
	return (ret);
}
