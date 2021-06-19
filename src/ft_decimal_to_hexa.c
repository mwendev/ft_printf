/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_to_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:14:47 by mwen              #+#    #+#             */
/*   Updated: 2021/06/18 12:19:19 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_conversion(unsigned long long ull, int base, char *address,
int count)
{
	while (ull != 0)
	{
		if ((ull % base) < 10)
			address[count - 1] = (ull % base) + 48;
		else
			address[count - 1] = (ull % base) + 55;
		ull /= base;
		count--;
	}
	return (address);
}

char	*ft_decimal_to_hexa(unsigned long long ull, int base)
{
	char				*address;
	unsigned long long	cp_ull;
	int					count;

	address = 0;
	count = 0;
	cp_ull = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	address = malloc((count + 1) * sizeof(char));
	if (!address)
		return (0);
	address[count] = '\0';
	address = ft_conversion(cp_ull, base, address, count);
	return (address);
}
