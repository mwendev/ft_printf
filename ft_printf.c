/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 15:53:49 by mwen              #+#    #+#             */
/*   Updated: 2021/06/19 15:48:15 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_init_flags(void)
{
	t_flags	flag;

	flag.type = 0;
	flag.width = 0;
	flag.minus = 0;
	flag.zero = 0;
	flag.dot = -1;
	flag.asterisk = 0;
	return (flag);
}

int	ft_flag_parse(const char *input, int i, t_flags *flags, va_list args)
{
	while (input[i])
	{
		if (!ft_isdigit(input[i]) && !ft_is_type(input[i])
			&& !ft_is_flag(input[i]))
			break ;
		if (input[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (input[i] == '.')
			i = ft_flag_dot(input, i, flags, args);
		if (input[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (input[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(input[i]))
			*flags = ft_flag_digit(input[i], *flags);
		if (ft_is_type(input[i]))
		{
			flags->type = input[i];
			break ;
		}
		++i;
	}
	return (i);
}

int	ft_treat_input(const char *input, va_list args)
{
	int		i;
	t_flags	flags;
	int		ret;

	i = 0;
	ret = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!input[i])
			break ;
		else if (input[i] == '%' && input[i + 1])
		{
			i = ft_flag_parse(input, ++i, &flags, args);
			if (ft_is_type(input[i]))
				ret += ft_treat_types(flags, args);
			else if (input[i])
				ret += ft_putchar(input[i]);
		}
		else if (input[i] != '%')
			ret += ft_putchar(input[i]);
		i++;
	}
	return (ret);
}

int	ft_printf(const char *input, ...)
{
	int			ret;
	va_list		args;

	ret = 0;
	va_start(args, input);
	ret += ft_treat_input(input, args);
	va_end(args);
	return (ret);
}
