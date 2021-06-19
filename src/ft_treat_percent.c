/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 12:06:54 by mwen              #+#    #+#             */
/*   Updated: 2021/06/19 13:28:46 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_percent(t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
	{
		ret += ft_putstrprec("%", 1);
		flags.zero = 0;
	}
	ret += ft_treat_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		ret += ft_putstrprec("%", 1);
	return (ret);
}
