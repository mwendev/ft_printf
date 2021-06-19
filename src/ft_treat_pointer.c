/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 22:29:20 by mwen              #+#    #+#             */
/*   Updated: 2021/06/19 15:16:40 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnullpointer(t_flags flags)
{
	int	ret;

	ret = 0;
	flags.width -= 2;
	if (flags.minus == 0)
		ret += ft_treat_width(flags.width, 0, 0);
	ret += ft_putstrprec("0x", 2);
	if (flags.minus == 1)
		ret += ft_treat_width(flags.width, 0, 0);
	return (ret);
}

static int	ft_putpointer(char *p, t_flags flags)
{
	int	ret;

	ret = 0;
	ret += ft_putstrprec("0x", 2);
	if (flags.dot >= 0)
	{
		ret += ft_treat_width(flags.dot, ft_strlen(p), 1);
		ret += ft_putstrprec(p, flags.dot);
	}
	else
		ret += ft_putstrprec(p, ft_strlen(p));
	return (ret);
}

int	ft_treat_pointer(unsigned long long ull, t_flags flags)
{
	char	*p;
	int		ret;

	ret = 0;
	if (ull == 0 && flags.dot == 0)
	{
		ret += ft_putnullpointer(flags);
		return (ret);
	}
	p = ft_decimal_to_hexa(ull, 16);
	p = ft_str_tolower(p);
	if ((size_t)flags.dot < ft_strlen(p))
		flags.dot = ft_strlen(p);
	if (flags.minus == 1)
		ret += ft_putpointer(p, flags);
	flags.width -= 2;
	ret += ft_treat_width(flags.width, ft_strlen(p), 0);
	if (flags.minus == 0)
		ret += ft_putpointer(p, flags);
	free(p);
	return (ret);
}
