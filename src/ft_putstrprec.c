/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 22:07:07 by mwen              #+#    #+#             */
/*   Updated: 2021/06/18 12:19:28 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstrprec(char *str, int prec)
{
	int	ret;

	ret = 0;
	while (str[ret] && ret < prec)
		ft_putchar(str[ret++]);
	return (ret);
}
