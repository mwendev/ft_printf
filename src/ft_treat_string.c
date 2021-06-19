/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 12:46:07 by mwen              #+#    #+#             */
/*   Updated: 2021/06/19 15:51:39 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putstr(char *str, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.dot >= 0)
		ret += ft_putstrprec(str, flags.dot);
	else
		ret += ft_putstrprec(str, ft_strlen(str));
	return (ret);
}

int	ft_treat_string(char *str, t_flags flags)
{
	int	ret;

	ret = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		ret += ft_putstr(str, flags);
	if (flags.dot >= 0)
		ret += ft_treat_width(flags.width, flags.dot, 0);
	else
		ret += ft_treat_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		ret += ft_putstr(str, flags);
	return (ret);
}
