/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:40:11 by mwen              #+#    #+#             */
/*   Updated: 2021/06/20 16:14:53 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putcharuint(char *uint_in_char, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.dot >= 0)
		ret += ft_treat_width(flags.dot, ft_strlen(uint_in_char), 1);
	ret += ft_putstrprec(uint_in_char, ft_strlen(uint_in_char));
	return (ret);
}

int	ft_treat_charuint(char *uint_in_char, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
		ret += ft_putcharuint(uint_in_char, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(uint_in_char))
		flags.dot = ft_strlen(uint_in_char);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ret += ft_treat_width(flags.width, 0, 0);
	}
	else
		ret += ft_treat_width(flags.width, ft_strlen(uint_in_char), flags.zero);
	if (flags.minus == 0)
		ret += ft_putcharuint(uint_in_char, flags);
	return (ret);
}

int	ft_treat_uint(unsigned int uint, t_flags flags)
{
	char	*uint_in_char;
	int		ret;

	ret = 0;
	if (flags.dot == 0 && uint == 0)
	{
		ret += ft_treat_width(flags.width, 0, 0);
		return (ret);
	}
	uint_in_char = ft_itoa(uint);
	ret += ft_treat_charuint(uint_in_char, flags);
	free(uint_in_char);
	return (ret);
}
