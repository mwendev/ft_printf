/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 11:53:21 by mwen              #+#    #+#             */
/*   Updated: 2021/06/19 15:52:20 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_treat_hexa(unsigned int uint, int lower, t_flags flags)
{
	char	*hexa_in_char;
	int		ret;

	ret = 0;
	if (flags.dot == 0 && uint == 0)
	{
		ret += ft_treat_width(flags.width, 0, 0);
		return (ret);
	}
	hexa_in_char = ft_decimal_to_hexa((unsigned long long)uint, 16);
	if (lower == 1)
		hexa_in_char = ft_str_tolower(hexa_in_char);
	ret += ft_treat_charuint(hexa_in_char, flags);
	free(hexa_in_char);
	return (ret);
}
